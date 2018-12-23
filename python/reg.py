import re
#直接给出字符是精确匹配
r = r'00'
print(re.match(r, "00") != None) #结果为True
# . 表示匹配任意字符
r = r'...'
print(re.match(r, "daf") != None) 
# \d可以匹配一个数字   \w 匹配一个字母或者数字


#对于变长字符  * 表示任意字符（包括一个）  + 表示至少一个   ？表示0个或者1个
#  {n}表示n个字符  {n,m} 表示 n到m个字符
# []表示范围 [a-z]表示a到z间任意一字符

r = r'[0-9a-zA-Z\_]'  #可以匹配任意数字，字母，下划线
print(re.match(r, '_fds') != None)


# A|B可以匹配A或者B  
r = r'^(a|b)$'
print(re.match(r, 'ad') != None)  #False

# 正则表达式用于切分字符串
print(re.split(r'\s+', "f,  adf fgf  a"))
# ['f,', 'adf', 'fgf', 'a']

# ()表示要提取的分组

r = r'^(\d{3})-(\d{3,8})$'
m = re.match(r, '132-1111111')
print(m.group(0))  #group(0)永远是原串
print(m.group(1))
print(m.group(1))
print(m.groups())


#贪婪匹配   正则匹配默认使用的是贪婪匹配
r = r'^(\d+)(0*)$'
m = re.match(r, '1300000000')
print(m.groups())
# ('1300000000', '')  第一个组将0全都给匹配掉了，导致第二个组为空
#给\d+后面加一个？可以使其变为非贪心匹配
r = r'^(\d+?)(0*)$'
m = re.match(r, '1300000000')
print(m.groups())
# ('13', '00000000')


# 编译  conpile方法返回一个正则表达式对象(Regular Expression)
re_telephone = re.compile(r'^(\d{3})-(\d{3,8})$')
print(re_telephone.match('010-12345').groups())
# ('010', '12345')
print(re_telephone.match('010-8086').groups())
# ('010', '8086')






