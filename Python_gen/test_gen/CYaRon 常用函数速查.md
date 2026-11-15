# CYaRon 常用函数速查

> 使用前导入：`from cyaron import *`

## 1. IO 文件输出模块（生成 .in /.out）

```
# 方式1：前缀+编号，生成 test1.in / test1.out
io = IO(file_prefix="test", data_id=1)

# 方式2：直接指定输入输出文件名
io = IO("a.in", "a.out")

# 指定输出文件夹（文件夹需要提前建好）
io = IO(file_prefix="test", data_id=1, output_dir="D:/testdata/")
```

| 函数                                  | 说明                                             |
| ------------------------------------- | ------------------------------------------------ |
| `io.input_writeln(a,b,c)`             | 写入一行，空格分隔，自动换行                     |
| `io.input_write(a,b,c)`               | 写入内容，**不换行**                             |
| `io.output_gen("D:\\std_binary.exe")` | 调用C++编译好的exe标程，自动生成 `.out` 标准答案 |

示例：

```
io = IO(file_prefix="t", data_id=2)
io.input_writeln(5, 10)
io.input_writeln(1, 2, 3, 4, 5)
```

## 2. 基础随机工具

| 函数              | 说明                                           |
| ----------------- | ---------------------------------------------- |
| `randint(l, r)`   | 生成 `[l, r]` 的随机整数                       |
| `randrange(l, r)` | 生成 `[l, r)` 的随机整数                       |
| `choice(list)`    | 从列表随机选取一个元素                         |
| `shuffle(list)`   | 将列表原地打乱                                 |
| `ati([0,10,1E4])` | 将数组全部转为int，处理 `1E4` 科学计数法浮点数 |

## 3. Sequence 序列（数组）

```
# n个随机整数，范围 [min, max]
arr = Sequence.random(n=10, min=1, max=100)

# 递增序列：1,2,3…n
arr = Sequence.increase(n)

# 递减序列：n,n‑1…1
arr = Sequence.decrease(n)

# 直接把数组写入输入文件
io.input_writeln(arr)
```

## 4. Graph 图论（OI高频）

```
# n点m边无向随机图，边权1~weight_limit，默认无自环、无重边
g = Graph.graph(n, m, weight_limit=20)

# 生成n个点的随机树
tree = Graph.tree(n, weight_limit=10)

# 生成有向图
g = Graph.graph(n, m, directed=True)

# 允许自环、允许重边
g = Graph.graph(n, m, self_loop=True, repeated_edges=True)
```

> 直接 `io.input_writeln(g)`，自动输出所有边 `u v w`。

## 5. Polygon / Vector 计算几何

```
# 生成300个随机点，坐标上限1000
pts = Vector.random(300, [1000, 1000])

# 随机凸包
hull = Polygon.convex_hull(300, fx=lambda x:int(x*1000), fy=lambda x:int(x*1000))
hull.perimeter()   # 获取周长
hull.area()        # 获取面积

# 根据点集生成随机简单多边形
poly = Polygon.simple_polygon(pts)
```

## 6. String 字符串

```
# 生成长度20的随机小写字母字符串
s = String.random(20)

# 指定字符集，只由 A B 构成
s = String.random(20, charset="AB")
```

## 7. 最小可运行模板

```
from cyaron import *

io = IO(file_prefix="data", data_id=1)
n = 10
a = Sequence.random(n, 1, 100)
io.input_writeln(n)
io.input_writeln(a)

# tree = Graph.tree(n, weight_limit=10)
# io.input_writeln(tree)
```

运行后在py脚本所在目录生成 `data1.in`。