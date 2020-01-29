def check(n, x, y):
    return (n - x) % y == 0


def main():
    try:
        while True:
            n, x, y = map(int, input().split())
            if check(n, x, y) or check(n, y, x):
                print("Yes")
            else:
                print("No")
    except:
        pass


if __name__ == "__main__":
    main()
