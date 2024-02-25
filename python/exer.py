def precedence(op):
    if op == '+' or op == '-':
        return 1
    elif op == '*' or op == '/':
        return 2
    return 0

def applyOp(val1, val2, op):
    if op == '+':
        return val1 + val2
    elif op == '-':
        return val1 - val2
    elif op == '*':
        return val1 * val2
    elif op == '/':
        return val1 / val2

def evaluate(tokens):
    ops = []
    values = []
    i = 0
    while i < len(tokens):
        if tokens[i].isdigit() or tokens[i] == '.':
            j = i
            while j < len(tokens) and (tokens[j].isdigit() or tokens[j] == '.'):
                j += 1
            values.append(float(tokens[i:j]))
            i = j
        elif tokens[i] == '(':
            ops.append(tokens[i])
            i += 1
        elif tokens[i] == ')':
            while (ops and ops[-1] != '('):
                val2 = values.pop()
                val1 = values.pop()
                op = ops.pop()
                values.append(applyOp(val1, val2, op))
            ops.pop()  # Xoa '('
            i += 1
        else:
            while (ops and (precedence(ops[-1]) >= precedence(tokens[i]))):
                val2 = values.pop()
                val1 = values.pop()
                op = ops.pop()
                values.append(applyOp(val1, val2, op))
            ops.append(tokens[i])
            i += 1
    while ops:
        val2 = values.pop()
        val1 = values.pop()
        op = ops.pop()
        values.append(applyOp(val1, val2, op))

    result = values[0]
    if result.is_integer():
        if tokens.rfind(".") != -1:
            return result
        else:
            return int(result)
    elif result - int(result) == 0.95:
        return round(result + 0.05, 1)
    else:
        return round(result, 1)

eps = input().strip()   #Xoa khoang trang dau cuoi
result = evaluate(eps)
print(result)


