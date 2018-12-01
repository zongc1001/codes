const superagent = require('superagent')
const cheerio = require('cheerio')
const fs = require('fs')

let arr = []
let len = 0

superagent
  .get('http://news.scu.edu.cn/cdzx.htm')
  .then(res => {
    let $ = cheerio.load(res.text)
    len = $('.c195338').length
    $('.c195338').each((index, element) => {
      let title = $(element).attr('title')
      let href = `http://news.scu.edu.cn/${$(element).attr('href')}`
      superagent.get(href).then(res2 => {
        let $ = cheerio.load(res2.text)
        let content = $('.v_news_content').text()
        let item = {
          title, href, content
        }
        arr.push(item)
        if (len === arr.length) {
          console.log('本页数据爬取完毕')
          fs.writeFileSync('output.csv', 'title, href, content\r\n')
          for (let item of arr) {
            fs.appendFileSync('output.csv', `"${item.title}", "${item.href}", "${item.content.replace(/\n/g, '')}"\r\n`)
            
          }
        }
      })
    })
  })
