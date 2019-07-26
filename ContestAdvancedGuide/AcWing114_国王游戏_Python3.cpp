# 2019-02-08
class node:

    def __init__(self, a, b):
        self.a = a
        self.b = b

    def __lt__(self, other):
        return self.a * self.b < other.a * other.b


def main():
    n = int(input())
    x, y = map(int, input().split())
    king = node(x, y)
    a = []
    for i in range(n):
        x, y = map(int, input().split())
        a.append(node(x, y))
    a.sort()
    ans = 0
    fact = king.a
    for x in a:
        tmp = fact // x.b
        if ans < tmp:
            ans = tmp
        fact *= x.a
    print(ans)


if __name__ == '__main__':
    main()
