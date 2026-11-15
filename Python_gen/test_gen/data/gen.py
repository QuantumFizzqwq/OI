# CYaron generator for P17828
# 修复：删掉 randstr，改用 random.choice
# 输出：string1.in ~ string25.in
from cyaron import *
import random
import string

random.seed(114514)

# --------------------------
# Subtask 1: n=1, small a_i <=5
# 测试点 1 -> string1.in
# --------------------------
io = IO(file_prefix="string", data_id=1)
n = 1
io.input_writeln(n)
a = randint(1,5)
c = random.choice(string.ascii_lowercase)
io.input_writeln(a, c)
io.output_gen("std")

# --------------------------
# Subtask 2~4: n<=2, a_i <=5
# 测试点 2,3,4 -> string2,3,4.in
# --------------------------
for tid in range(2,5):
    io = IO(file_prefix="string", data_id=tid)
    n = randint(1,2)
    io.input_writeln(n)
    for _ in range(n):
        a = randint(1,5)
        c = random.choice(string.ascii_lowercase)
        io.input_writeln(a, c)
    io.output_gen("std")

# --------------------------
# Subtask5,6: n<=10, a_i = 1
# 测试点5,6 -> string5,6.in
# --------------------------
for tid in range(5,7):
    io = IO(file_prefix="string", data_id=tid)
    n = randint(1,10)
    io.input_writeln(n)
    for _ in range(n):
        c = random.choice(string.ascii_lowercase)
        io.input_writeln(1, c)
    io.output_gen("std")

# --------------------------
# Subtask7,8: n<=10, a_i <=50
# 测试点7,8 -> string7,8.in
# --------------------------
for tid in range(7,9):
    io = IO(file_prefix="string", data_id=tid)
    n = randint(1,10)
    io.input_writeln(n)
    for _ in range(n):
        a = randint(1,50)
        c = random.choice(string.ascii_lowercase)
        io.input_writeln(a, c)
    io.output_gen("std")

# --------------------------
# Subtask9: n<=2000, a_i =1
# 测试点9 -> string9.in
# --------------------------
io = IO(file_prefix="string", data_id=9)
n = randint(1,2000)
io.input_writeln(n)
for _ in range(n):
    c = random.choice(string.ascii_lowercase)
    io.input_writeln(1, c)
io.output_gen("std")

# --------------------------
# Subtask10~12: n<=2000, a_i <=50
# 测试点10,11,12 -> string10,11,12.in
# --------------------------
for tid in range(10,13):
    io = IO(file_prefix="string", data_id=tid)
    n = randint(1,2000)
    io.input_writeln(n)
    for _ in range(n):
        a = randint(1,50)
        c = random.choice(string.ascii_lowercase)
        io.input_writeln(a, c)
    io.output_gen("std")

# --------------------------
# Subtask13~16: n<=2000, a_i up to 1e9
# 测试点13~16 -> string13~16.in
# --------------------------
for tid in range(13,17):
    io = IO(file_prefix="string", data_id=tid)
    n = randint(1,2000)
    io.input_writeln(n)
    for _ in range(n):
        a = randint(1, 10**9)
        c = random.choice(string.ascii_lowercase)
        io.input_writeln(a, c)
    io.output_gen("std")

# --------------------------
# Subtask17,18: n<=2e5, a_i = 1
# 测试点17,18 -> string17,18.in
# --------------------------
for tid in range(17,19):
    io = IO(file_prefix="string", data_id=tid)
    n = randint(1, 200000)
    io.input_writeln(n)
    arr = []
    for _ in range(n):
        ch = random.choice(string.ascii_lowercase)
        arr.append(f"1 {ch}")
    io.input_write("\n".join(arr)+"\n")
    io.output_gen("std")

# --------------------------
# Subtask19~21: n<=2e5, a_i <=50
# 测试点19~21 -> string19~21.in
# --------------------------
for tid in range(19,22):
    io = IO(file_prefix="string", data_id=tid)
    n = randint(1, 200000)
    io.input_writeln(n)
    arr = []
    for _ in range(n):
        a = randint(1,50)
        ch = random.choice(string.ascii_lowercase)
        arr.append(f"{a} {ch}")
    io.input_write("\n".join(arr)+"\n")
    io.output_gen("std")

# --------------------------
# Subtask22~25: n<=2e5, a_i up to 1e9
# 测试点22~25 -> string22~25.in
# --------------------------
for tid in range(22,26):
    io = IO(file_prefix="string", data_id=tid)
    n = randint(1, 200000)
    io.input_writeln(n)
    arr = []
    for _ in range(n):
        a = randint(1, 10**9)
        ch = random.choice(string.ascii_lowercase)
        arr.append(f"{a} {ch}")
    io.input_write("\n".join(arr)+"\n")
    io.output_gen("std")
