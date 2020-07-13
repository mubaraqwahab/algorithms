# Use 'pip3 install algorithms' to install the package

from algorithms.stack import LinkedListStack


def convert_infix_to_postfix(infix):
    """Convert an infix expression to a postfix expression."""

    stack = LinkedListStack()
    postfix = ""

    # Iterate through every character in the infix.
    for char in infix.split():
        # If char is an operand, place in the output.
        if is_operand(char):
            postfix += char + ' '

        # If char is an operator, and char has
        # lower or equal priority than the stack top,
        # pop the stack top and place in the output.
        # Continue doing this
	    # until the stack top has greater priority.
        # Then push to stack.
        elif is_operator(char):
            while (stack and
		   priority(char) <= priority(stack.peek())):
                postfix += stack.pop() + ' '
            stack.push(char)

        # If char is a left parenthesis, push to stack.
        elif char == '(':
            stack.push(char)

        # If char is a right parenthesis,
        # pop every operator in the stack and place in output,
        # until you reach a left parenthesis,
        # then discard both parentheses.
        elif char == ')':
            popped_item = stack.pop()
            while popped_item != '(':
                postfix += popped_item + ' '
                popped_item = stack.pop()

    # Place whatever remains in the stack in the output.
    while stack:
        postfix += stack.pop() + ' '

    return postfix

def is_operand(char):
    """Return True if char is an operand, False otherwise."""
    return char.isalnum()

def is_operator(char):
    """Return True if char is an operator, False otherwise."""
    return char in ('+', '-', '*', '/', '%', '//', '**')

def priority(operator):
    """Return the numeric value of operator priority."""
    return { '**': 3, '//': 2, '%': 2, '*': 2,
            '/': 2, '+': 1, '-': 1, '(': 0 } [operator]


if __name__ == "__main__":
    # Make sure you space out the expression
    infix = "x ** y / ( 5 * z ) + 10"
    print("Infix:", infix)

    postfix = convert_infix_to_postfix(infix)
    print("Postfix:", postfix)