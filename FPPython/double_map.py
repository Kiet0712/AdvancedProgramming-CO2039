def doubler(x):
  """This function doubles an input number."""
  return x * 2

numbers = [1, 2, 3, 4]
doubled_numbers = map(doubler, numbers)

# Convert the map object to a list for easy printing
print(list(doubled_numbers))  # Output: [2, 4, 6, 8]