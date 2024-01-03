#数据框
#类似矩阵，可包含不同数据类型，列必须命名

#data.frame创建数据框
book_name <- c("biochenistry", "cell biology", "molecular biology");book_name
book_price <- c(314, 339, 372);book_price
book_evaluate <- c(4.6, 4.8, 4.2);book_evaluate
book <- data.frame(book_name, book_price, book_evaluate);book

#访问列或行
book[c(2, 3),]#访问第2、3行
book[,c(1, 2)]; book[,c("book_name", "book_price")]#访问第1, 2列
book[1, 3]#访问特定元素

a <- seq(1, 100, 2);a
b <- seq(312, 421, , 50);b
c <- data.frame(a, b);c
plot(c$a, c$b)#使用$访问列
with(c, {a})#使用with访问列

rm(a);rm(b);a;b;attach(c);a;b#使用attach(数据框)后可直接输入列名访问
detach(c)#detach用于取消加载


#因子
#名义型变量、有序性变量、连续型变量
#名义型变量与有序性变量称为因子, factor，这些水平值构成的向量可称为一个因子
#因子中不同的水平值称为level

mtcars;table(mtcars$cyl)#将mtcars数据集中的cyl作为因子进行频数统计

#定义因子类型的数据及因子水平
a <- factor(c(9, 4, 1, 3, 8, 2, 3, 6, 5, 3, 5, 1, 4, 2, 7, 1));a
a <- factor(c("Fri", "Mon", "Tue", "Wen", "Sun"), ordered = T, levels = c("Mon", "Tue", "Wen", "Thur", "Fri", "Sat", "Sun"));a

#定义表格中的因子
fcyl <- factor(mtcars$cyl, ordered = T);fcyl
plot(fcyl)#对于因子绘制条形图

#cut函数将连续型变量分组
a <- seq(1, 100, 2)
cut(a, c(seq(0, 100, 20)))


#缺失值NA的处理
a <- c(NA, 1:21, NA, 8:24)
is.na(a)#使用is.na返回对应位置是否为NA的判断(T/F)构成的向量
sum(a);sum(a, na.rm = T)#使用na.rm = T 使计算函数跳过NA
b <- na,omit(a)#na.omit处理向量或数据框除去NA


#字符串
nchar("biochemistry")#字符串长度，对向量使用返回各元素字符数的向量
paste("haha", "hehe", "hihi", sep = " or ")
#将字符串以sep中的字符串相连，对向量使用时即对向量中每个元素使用

#substr提取字符串
mon <- substr(month.name, 1, 3)
toupper(mon)#转换为大写
tolower(mon)#转换为小写

