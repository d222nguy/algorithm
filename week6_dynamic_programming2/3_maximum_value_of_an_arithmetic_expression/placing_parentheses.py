# Uses python3
def evalt(a, b, op):
    if op == '+':
        return a + b
    elif op == '-':
        return a - b
    elif op == '*':
        return a * b
    else:
        assert False

def get_maximum_value(dataset):
    #write your code here
    op = []
    num = []
    for i in range(len(dataset)):
        if (dataset[i] == '-' or dataset[i] == '+' or dataset[i] == '*' or dataset[i] == '/'):
            op.append(dataset[i])
        else:
            num.append(float(dataset[i]))
    m = [[float('inf') for i in range(len(dataset))] for j in range(len(dataset))]
    M = [[float('-inf') for i in range(len(dataset))] for j in range(len(dataset))]
    for i in range(len(num)):
        m[i][i] = num[i]
        M[i][i] = num[i]
    for i in range(1, len(num)):
        for j in range(len(num) - i):
            for k in range(i):
                a = m[j][j + k]
                A = M[j][j + k]
                b = m[j + k + 1][j + i]
                B = M[j + k + 1][j + i]
                cand = min(evalt(a, b, op[j + k]), evalt(a, B, op[j + k]), evalt(A, b,      op[j + k]), evalt(A, B, op[j + k]))
                Cand = max(evalt(a, b, op[j + k]), evalt(a, B, op[j + k]), evalt(A, b,      op[j + k]), evalt(A, B, op[j + k]))
                m[j][j + i] = min(m[j][j + i], cand)
                M[j][j + i] = max(M[j][j + i], Cand)
    
    return int(M[0][len(num) - 1])


if __name__ == "__main__":
    print(get_maximum_value(input()))
