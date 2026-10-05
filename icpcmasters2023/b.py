MOD = 10**9 + 7


def multiply(a: list[list[int]], b: list[list[int]]) -> list[list[int]]:
    size = len(a)
    return [
        [
            sum(a[i][k] * b[k][j] for k in range(size)) % MOD
            for j in range(size)
        ]
        for i in range(size)
    ]


def matrix_power(matrix: list[list[int]], exponent: int) -> list[list[int]]:
    size = len(matrix)
    result = [[int(i == j) for j in range(size)] for i in range(size)]

    while exponent:
        if exponent & 1:
            result = multiply(result, matrix)
        matrix = multiply(matrix, matrix)
        exponent >>= 1

    return result


def main() -> None:
    k = int(input())

    if k == 1:
        print(2)
        return
    if k == 2:
        print(3)
        return

    transition = [
        [3, 2, 1, 3],
        [1, 0, 0, 0],
        [0, 1, 0, 0],
        [0, 0, 0, 1],
    ]
    power = matrix_power(transition, k - 2)
    initial = [3, 2, 1, 1]

    answer = sum(power[0][i] * initial[i] for i in range(4)) % MOD
    print(answer)


if __name__ == "__main__":
    main()
    