typeof(a)
mode(a)

#向量

#c函数连接
x <- c(1, 2, 3, 4, 5)
y <- c("one", "two")
z <- c(TRUE, T, F)#用于逻辑判断

#构建等差数列
a1 <- 1:100#构建1~100等差数列
a2 <- seq (form = 1, to = 100, by = 2)#by用于描述两项差
a3 <- seq (form = 1, to = 100, length.out = 10)#length.out用以描述总项数

#rep重复数值或变量
rep(5, 2)#rep(重复项目, 重复次数)
#对于向量的重复
x <- c(1, 2, 3, 4, 5)
rep(x, each = 3, times = 4)#each为单个元素的重复次数，times为向量整体重复次数

#向量长度统计
length(x)

#向量的访问与索引
#向量的访问为[]，下标以1开始
x <- seq(from = 1, to = 10, by = 1)
x[c(3, 4, 6)]#访问多个下标以逗号相隔
x[1:5] <- c(5,5,3,2,1)#访问/赋值下标1~5的元素
x[c(T, F)]#以逻辑判断访问，输出判断为真的数，按照顺序循环判断
x[ x > 3 & x <= 5]#按照元素本身判断
which( 5 == x )#通过内容寻找索引值


#若输入负数，则不输出该数绝对值位置的元素
x <- seq(from = 1, to = 6, by = 1)
x[-2][-4]#过程为从左向右，除去2后第四位为5，故输出1 3 4 6

#字符向量
char <- c("the", "data", "was")
"the" %in% char #判断"the"是否在向量char中存在(遍历所有元素)，返回值TURE或FALSE
char %in% c("the", "data")
#分别判断向量char中的每个元素是否存在于后一向量中，输出TURE或FALSE的向量

#对向量命名
x <- seq(from = 1, to = 3, by = 1)
names(x) <- c("one", "two", "three")#names函数访问向量元素名称
x["one"]#利用名称属性访问向量元素

#插入数据
arr <- seq(from = 1, to = 10, by = 1)
append(x = arr, values = 213, after = 6)
#向量arr的第6个元素后插入元素213，after = 0可在头部插入数据

#向量运算
arr1 <- seq(from = 1, to = 10, by = 1)
arr1 <- seq(from = 1, to = 47, by = 1)
arr + 1 #对向量arr的每个元素均执行相同的操作
#运算符包括：+  - *(乘法) **(幂运算)  /(除法) %/%(整除) %%(取模)

#当向量元素个数不等时，较短向量循环使用，非倍数关系会报错

#运算函数
x <- (-5:5)
sqrt(x)#算数平方根
abs(x)#绝对值
log(x, base = 2)#log运算，base为底数
  log(x)#无底数时默认自然对数
  log10(x)#lg函数
exp(x)#计算以e为底的指数
ceiling(x)#返回不小于x的最小整数
floor(x)#返回不大于x的最小整数
trunc(x)#返回整数部分
round(x, digits = 3)#四舍五入至小数点后digits位
signif(x, digits = 3)#取digits位有效数字

#统计函数
x <- seq(from = 1, to = 100, by = 2)
sum(x)#求和
max(x)#最大值
min(x)#最小值
range(x)#同时返回最大和最小
mean(x)#均值
mediun(x)#中位数
var(x)#方差
sd(x)#标准差
prod(x)#连乘积
quantile(x, c(0.4, 0.5, 0.8))#分位数计算，分位组成向量形式表示

#矩阵

#矩阵的创建
a <- matrix(1:24, nrow = 4, ncol = 6, byrow = FALSE
  #创建矩阵的向量   行数      列数    是否按行排列
a <- matrix(1:24, 4, 6, byrow = T)
rnames <- c("R1", "R2", "R3", "R4")
cnames <- c("C1", "C2", "C3", "C4", "C5", "C6")
dimnames(a) <- list(rnames, cnames);a

#dim
a <- 1:20
dim(a) <- c(2, 5, 2);a#创建多维数组

#array
#具有data、dim与dimnames共三个参数
dim1 <- c("A1", "A2")
dim2 <- c("B1", "B2")
dim3 <- c("C1", "C2")
a <- array(seq(from = 2, to = 16, outer = 8), c(2, 2, 2), list(dim1, dim2, dim3))

#矩阵的访问
a <- matrix(1:24, 4, 6, byrow = T)
rnames <- c("R1", "R2", "R3", "R4")
cnames <- c("C1", "C2", "C3", "C4", "C5", "C6")
dimnames(a) <- list(rnames, cnames)
a[2,]; a[,1]#利用矩阵下标访问特定行、列
a[,"C2"]; a["R4",]#利用矩阵的行列名访问特定行、列


#矩阵的运算
a <- matrix(1:20, 4, 5);a
b <- matrix(23:4, 4, 5);b
a + b#矩阵加法：对应元素相加
a - b#矩阵减法：对应元素相减
colSums(a)
rowSums(a)#矩阵的行列和
colMeans(a)
rowMeans(a)#矩阵的行列平均数
a * b#矩阵内积：对应元素相乘
a %*% b#矩阵外积
diag(a)#主对角元素
t(a)#矩阵转置

#列表
#列表是对象(列表、向量、矩阵、数据框等)的有序集合，可混合及嵌套存储
a <- 1
b <- matrix(23:4, 4, 5)
c <- 34:21
list1 <- list(listtest_number = a, listtest_matrix = b, listtest_arr = c)#定义列表
list1[1];list1[c(1, 2)]#利用下标访问一个或多个元素
list1["listtest_number"];list1[c("listtest_number", "listtest_matrix")]
list1$listtest_number#利用名称访问多个元素

#可使用负索引或NULL赋值来删除元素