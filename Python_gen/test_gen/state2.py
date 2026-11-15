import matplotlib.pyplot as plt
n, m = 2, 2
fig, ax = plt.subplots(figsize=(5, 5))
# 画网格线
for x in range(n+1):
    ax.plot([x, x], [0, m], c='gray', lw=1)
for y in range(m+1):
    ax.plot([0, n], [y, y], c='gray', lw=1)
# 绘制格点+文字标注
for i in range(n+1):
    for j in range(m+1):
        ax.scatter(i, j, c='black')
        ax.text(i+0.05,j+0.05,f'({i},{j})')
# 线段 (1,0) — (2,2)
ax.plot([1, 2], [0, 2], color='red', linewidth=2)
# 灰色填充挖去的矩形
rect = plt.Rectangle((0, 0), 1, 1, color='lightgray')
ax.add_patch(rect)
ax.set_aspect('equal')
plt.xlim(-0.2, n+0.2)
plt.ylim(-0.2, m+0.2)
plt.show()
