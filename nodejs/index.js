const superagent = require('superagent');
const cheerio = require('cheerio');
const fs = require('fs');

let arr = [];
let len = 0;

superagent.get('http://news.scu.edu.cn/')
.then(res => { //then方法是异步执行，当前面的函数执行完成后再运行then方法，这样可避免数据没有获得的情况
    len = $('.c195312').length;
    let $ = cheerio.load(res.text);
    

    $('.c195312').each((index, element) => {
        let title = $(element).attr('title');
        let href = `http://news.scu.edu.cn/${$(element).attr('href')}`;
        superagent.get(href).then(res2 => {
            let $ = cheerio.load(res2.text);
            let content = $('.v_news_content').text();
            let item = {
                title, item, content
            }
            arr.push(item);
            if(len === arr.length)
            {
                console.log('本页数据已爬取完毕');
                fs.writeFileSync('output.json', JSON.stringify(arr));
            }

            
        })

    })

    

})



