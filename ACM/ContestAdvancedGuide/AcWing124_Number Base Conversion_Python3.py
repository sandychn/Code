# 2019-02-09
def main():
    change = '0123456789'
    for i in range(0, 26):
        change += chr(i + 65)
    for i in range(0, 26):
        change += chr(i + 97)
    T = int(input())
    while T:
        T -= 1
        a, b, s = input().split()
        a, b = int(a), int(b)
        number = 0
        for x in s:
            number *= a
            if 48 <= ord(x) <= 57:
                number += ord(x) - 48
            elif 65 <= ord(x) <= 90:
                number += ord(x) - 65 + 10
            else:
                number += ord(x) - 97 + 36
        ans = ''
        while number:
            ans += change[number % b]
            number //= b
        if not ans:
            ans = '0'
        print(a, s)
        print(b, ans[::-1])
        print()


if __name__ == '__main__':
    main()
