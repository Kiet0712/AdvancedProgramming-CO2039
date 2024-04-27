def doubler(x):
  """This function doubles an input number."""
  return x * 2
def add_five(x):
  """This function adds five to an input number."""
  return x + 5

def compose(f, g):
  """
  This function takes two functions f and g and returns a new function h
  such that h(x) = f(g(x)). This is called function composition.
  """
  def h(x):
    return f(g(x))
  return h

# Create a new function that first adds five and then doubles the result
add_five_then_double = compose(doubler, add_five)

# Use the new function
result = add_five_then_double(5)
print(result)  # Output: 20