#generator
log_lines = (line for line in read_line(huge_log_file) if complex_condition(line))
#imperative version
def get_log_lines(log_file):
 line = read_line(log_file)
 while True:
    try:
        if complex_condition(line):
            yield line
        line = read_line(log_file)
    except StopIteration:
        raise
log_lines = get_log_lines(huge_log_file)