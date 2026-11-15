import random
from cyaron import *

random.seed(998244353)
# Windows 路径，r""原始字符串，不需要手动预先建data文件夹也可以，不存在会IO报错，建议手动新建data文件夹
OUT_DIR = r".\data\\"

# ====================== 题目1：环（糖果） 10组【全部保证至少1解】 ======================
def gen_problem1():
    """题目1 环，输出 1_1.in ~1_10.in，所有测试点保证至少1个合法方案"""
    cases_cfg = [
        {"type":"sample"},          #1 原样例（自带解）
        {"type":"all_k1","n":4},    #2 全部k_i=1，强制环合法（相邻糖果不同）
        {"type":"all_k1","n":6},    #3 全部k_i=1，合法环
        {"type":"max_n"},           #4 n=8满规模，有解
        {"type":"branch","n":7},    #5 n=7高分支，保证存在解
        {"type":"random","n":4},    #6 n=4中等随机
        {"type":"random","n":5},    #7 n=5随机
        {"type":"max_n"},           #8 n=8另一组
        {"type":"random","n":7},    #9 n=7随机
        {"type":"random","n":8},    #10 n=8完全随机
    ]

    def build(io, cfg):
        t = cfg["type"]
        if t == "sample":
            io.input_writeln(4)
            io.input_writeln(2,1,2)
            io.input_writeln(3,1,3,4)
            io.input_writeln(1,3)
            io.input_writeln(2,2,4)
            return

        if t == "all_k1":
            # 全部k_i=1，手动构造合法环形序列：相邻不同、首尾不同
            n = cfg["n"]
            io.input_writeln(n)
            seq = []
            for i in range(n):
                if i < n-1:
                    seq.append(1 if i%2==0 else 2)
                else:
                    if n%2 ==0:
                        seq.append(1 if (n-1)%2==0 else 2)
                    else:
                        seq.append(3)
            for num in seq:
                io.input_writeln(1, num)
            return

        if t == "max_n":
            n=8
            io.input_writeln(n)
            sol = [1,2,1,2,1,2,1,3]
            for i in range(n):
                ki = random.randint(2,8)
                cand = set()
                cand.add(sol[i])
                others = list(set(range(1,11)) - {sol[i]})
                add = random.sample(others, ki-1)
                cand.update(add)
                lst = list(cand)
                random.shuffle(lst)
                io.input_writeln(ki, *lst)
            return

        if t == "branch":
            n=cfg["n"]
            io.input_writeln(n)
            sol = []
            for i in range(n):
                sol.append(1 if i%2==0 else 2)
            if n%2 ==1:
                sol[-1]=3
            for i in range(n):
                ki = random.randint(6,8)
                cand = set()
                cand.add(sol[i])
                others = list(set(range(1,11)) - {sol[i]})
                add = random.sample(others, ki-1)
                cand.update(add)
                lst = list(cand)
                random.shuffle(lst)
                io.input_writeln(ki, *lst)
            return

        if t == "random":
            n=cfg["n"]
            io.input_writeln(n)
            sol = []
            for i in range(n):
                sol.append(1 if i%2==0 else 2)
            if n%2 ==1:
                sol[-1]=3
            for i in range(n):
                ki = random.randint(2,8)
                cand = set()
                cand.add(sol[i])
                others = list(set(range(1,11)) - {sol[i]})
                add = random.sample(others, ki-1)
                cand.update(add)
                lst = list(cand)
                random.shuffle(lst)
                io.input_writeln(ki, *lst)
            return

    for idx,cfg in enumerate(cases_cfg, start=1):
        in_file = f"{OUT_DIR}1_{idx}.in"
        io = IO(input_file=in_file)
        build(io, cfg)
        io.close()


# ====================== 题目2：因数 10组 ======================
def gen_problem2():
    cases_cfg = [
        {"type":"sample"},
        {"type":"kmax_edge"},
        {"type":"d_very_small"},
        {"type":"d_ge_n"},
        {"type":"distinct_prime"},
        {"type":"ans_zero"},
        {"type":"mid_random"},
        {"type":"mid_random"},
        {"type":"heavy_dup"},
        {"type":"big_d_random"},
    ]
    def build(io, cfg):
        t = cfg["type"]
        if t == "sample":
            io.input_writeln(4,15)
            io.input_writeln(2,3,5,2)
            return
        if t == "kmax_edge":
            k=100
            d = random.randint(1, 10**18)
            io.input_writeln(k, d)
            ps = [random.choice([2,3,5,7]) for _ in range(k)]
            io.input_writeln(*ps)
            return
        if t == "d_very_small":
            k = random.randint(2,60)
            d=1
            io.input_writeln(k, d)
            ps = [random.randint(2, int(1e9)) for _ in range(k)]
            io.input_writeln(*ps)
            return
        if t == "d_ge_n":
            k=random.randint(5,40)
            ps = [random.choice([2,3,5,7,11]) for _ in range(k)]
            d = 10**18
            io.input_writeln(k, d)
            io.input_writeln(*ps)
            return
        if t == "distinct_prime":
            small_primes = [2,3,5,7,11,13,17,19,23,29,31,37,41,43,47]
            k = random.randint(5, len(small_primes))
            ps = random.sample(small_primes, k)
            d = random.randint(1, 10**18)
            io.input_writeln(k, d)
            io.input_writeln(*ps)
            return
        if t == "ans_zero":
            p = random.randint(100, 10**9)
            k = random.randint(2,50)
            d = random.randint(2, p-1)
            ps = [p]*k
            io.input_writeln(k, d)
            io.input_writeln(*ps)
            return
        if t == "heavy_dup":
            k=100
            p = random.choice([2,3,5])
            ps = [p]*k
            d = random.randint(1, 10**18)
            io.input_writeln(k, d)
            io.input_writeln(*ps)
            return
        if t == "mid_random":
            k = random.randint(1, 100)
            d = random.randint(1, 10**18)
            ps = []
            for _ in range(k):
                ps.append(random.randint(2, int(1e9)))
            io.input_writeln(k, d)
            io.input_writeln(*ps)
            return
        if t == "big_d_random":
            k = random.randint(1,100)
            d = random.randint(10**12, 10**18)
            ps = [random.randint(2, int(1e9)) for _ in range(k)]
            io.input_writeln(k, d)
            io.input_writeln(*ps)
            return

    for idx,cfg in enumerate(cases_cfg, start=1):
        in_file = f"{OUT_DIR}2_{idx}.in"
        io = IO(input_file=in_file)
        build(io, cfg)
        io.close()

# ====================== 题目3：子矩阵 10组 ======================
def gen_problem3():
    cases_cfg = [
        {"type":"sample"},
        {"type":"max_size"},
        {"type":"all_neg"},
        {"type":"r_eq_n_c_eq_m"},
        {"type":"r=1"},
        {"type":"c=1"},
        {"type":"small_random"},
        {"type":"mid_random"},
        {"type":"mix_pos_neg_large"},
        {"type":"edge_r_c"},
    ]
    def build(io, cfg):
        t=cfg["type"]
        if t=="sample":
            io.input_writeln(3,4,2,2)
            io.input_writeln(-1,4,-2,1)
            io.input_writeln(2,-3,-2,0)
            io.input_writeln(1,-1,1,-5)
            return
        if t=="max_size":
            n,m=22,22
            r = random.randint(1,n)
            c = random.randint(1,m)
            io.input_writeln(n,m,r,c)
            for _ in range(n):
                row = [random.randint(-10**6, 10**6) for __ in range(m)]
                io.input_writeln(*row)
            return
        if t=="all_neg":
            n = random.randint(8,18)
            m = random.randint(8,18)
            r = random.randint(1,n)
            c = random.randint(1,m)
            io.input_writeln(n,m,r,c)
            for _ in range(n):
                row = [random.randint(-10**6, -1) for __ in range(m)]
                io.input_writeln(*row)
            return
        if t=="r_eq_n_c_eq_m":
            n = random.randint(6,16)
            m = random.randint(6,16)
            r,c = n,m
            io.input_writeln(n,m,r,c)
            for _ in range(n):
                row = [random.randint(-10**6,10**6) for __ in range(m)]
                io.input_writeln(*row)
            return
        if t=="r=1":
            n = random.randint(5,22)
            m = random.randint(5,22)
            r=1
            c = random.randint(1,m)
            io.input_writeln(n,m,r,c)
            for _ in range(n):
                row = [random.randint(-10**6,10**6) for __ in range(m)]
                io.input_writeln(*row)
            return
        if t=="c=1":
            n = random.randint(5,22)
            m = random.randint(5,22)
            r = random.randint(1,n)
            c=1
            io.input_writeln(n,m,r,c)
            for _ in range(n):
                row = [random.randint(-10**6,10**6) for __ in range(m)]
                io.input_writeln(*row)
            return
        if t=="small_random":
            n = random.randint(1,12)
            m = random.randint(1,12)
            r = random.randint(1,n)
            c = random.randint(1,m)
            io.input_writeln(n,m,r,c)
            for _ in range(n):
                row = [random.randint(-10**6,10**6) for __ in range(m)]
                io.input_writeln(*row)
            return
        if t=="mid_random":
            n = random.randint(13,21)
            m = random.randint(13,21)
            r = random.randint(1,n)
            c = random.randint(1,m)
            io.input_writeln(n,m,r,c)
            for _ in range(n):
                row = [random.randint(-10**6,10**6) for __ in range(m)]
                io.input_writeln(*row)
            return
        if t=="mix_pos_neg_large":
            n = random.randint(10,22)
            m = random.randint(10,22)
            r = random.randint(1,n)
            c = random.randint(1,m)
            io.input_writeln(n,m,r,c)
            for _ in range(n):
                row = []
                for __ in range(m):
                    if random.random()<0.5:
                        val = random.randint(800000, 10**6)
                    else:
                        val = random.randint(-10**6, -800000)
                    row.append(val)
                io.input_writeln(*row)
            return
        if t=="edge_r_c":
            n = random.randint(10,22)
            m = random.randint(10,22)
            if random.random()<0.5:
                r,c = n,1
            else:
                r,c =1,m
            io.input_writeln(n,m,r,c)
            for _ in range(n):
                row = [random.randint(-10**6,10**6) for __ in range(m)]
                io.input_writeln(*row)
            return

    for idx,cfg in enumerate(cases_cfg, start=1):
        in_file = f"{OUT_DIR}3_{idx}.in"
        io = IO(input_file=in_file)
        build(io, cfg)
        io.close()

# ====================== 题目4：路径数量 8组 ======================
def gen_problem4():
    """
    T4 路径数量，20组，严格对齐原题测试点划分
    ✅ 原题强制：**输出文件编号为奇数的测试点，全部a_{k,i,j} ∈ {0, 1}**
    1~5: m=1
    6~10: m≤3, n≤5
    11~15: m≤4, n≤7
    16~18: m≤10, n≤8
    19~20: 无附加限制 m=20,n=9
    """
    cases_cfg = [
        # 1‑5 m=1
        {"type":"sample"},
        {"type":"m_eq_1"},
        {"type":"m_eq_1"},
        {"type":"m_eq_1"},
        {"type":"m_eq_1"},
        # 6‑10 m<=3,n<=5
        {"type":"small_m_n"},
        {"type":"small_m_n"},
        {"type":"small_m_n"},
        {"type":"small_m_n"},
        {"type":"small_m_n"},
        #11‑15 m<=4,n<=7
        {"type":"mid_m_n"},
        {"type":"mid_m_n"},
        {"type":"mid_m_n"},
        {"type":"mid_m_n"},
        {"type":"mid_m_n"},
        #16‑18 m<=10,n<=8
        {"type":"ten_m_n"},
        {"type":"ten_m_n"},
        {"type":"ten_m_n"},
        #19‑20 max极限
        {"type":"max_limit"},
        {"type":"max_limit"},
    ]

    def build(io, cfg, is_odd_case):
        """is_odd_case=True:奇数测试点，只能输出0/1"""
        t = cfg["type"]
        if t == "sample":
            io.input_writeln(1,3)
            io.input_writeln(0,1,2)
            io.input_writeln(2,1,1)
            io.input_writeln(3,2,2)
            return

        if t == "m_eq_1":
            m = 1
            n = random.randint(2,9)
            io.input_writeln(m,n)
            for _ in range(n):
                if is_odd_case:
                    row = [random.randint(0,1) for __ in range(n)]
                else:
                    row = [random.randint(0, 10**9) for __ in range(n)]
                io.input_writeln(*row)
            return

        if t == "small_m_n":
            m = random.randint(2,3)
            n = random.randint(2,5)
            io.input_writeln(m,n)
            for _ in range(m):
                for _i in range(n):
                    if is_odd_case:
                        row = [random.randint(0,1) for __ in range(n)]
                    else:
                        row = [random.randint(0,10**9) for __ in range(n)]
                    io.input_writeln(*row)
            return

        if t == "mid_m_n":
            m = random.randint(2,4)
            n = random.randint(2,7)
            io.input_writeln(m,n)
            for _ in range(m):
                for _i in range(n):
                    if is_odd_case:
                        row = [random.randint(0,1) for __ in range(n)]
                    else:
                        row = [random.randint(0,10**9) for __ in range(n)]
                    io.input_writeln(*row)
            return

        if t == "ten_m_n":
            m = random.randint(5,10)
            n = random.randint(2,8)
            io.input_writeln(m,n)
            for _ in range(m):
                for _i in range(n):
                    if is_odd_case:
                        row = [random.randint(0,1) for __ in range(n)]
                    else:
                        row = [random.randint(0,10**9) for __ in range(n)]
                    io.input_writeln(*row)
            return

        if t == "max_limit":
            m = 20
            n =9
            io.input_writeln(m,n)
            for _ in range(m):
                for _i in range(n):
                    if is_odd_case:
                        row = [random.randint(0,1) for __ in range(n)]
                    else:
                        row = [random.randint(0, 10**9) for __ in range(n)]
                    io.input_writeln(*row)
            return

    for idx, cfg in enumerate(cases_cfg, start=1):
        in_file = f"{OUT_DIR}4_{idx}.in"
        io = IO(input_file=in_file)
        # 原题规则：测试点编号idx为奇数，a只能0/1
        build(io, cfg, is_odd_case = (idx %2 == 1))
        io.close()

# ============ 执行生成全部 ============
if __name__ == "__main__":
    import os
    if not os.path.exists(r".\data"):
        os.mkdir(r".\data")
        print("自动创建data文件夹")

    gen_problem1()
    gen_problem2()
    gen_problem3()
    gen_problem4()
    print("全部数据生成完成，输出目录：", OUT_DIR)
