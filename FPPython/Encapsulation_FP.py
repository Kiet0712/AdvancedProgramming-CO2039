def make_collection():
    collection = []
    state_var = True
    for datum in range(10):
        if state_var:
            collection.append(datum)
            state_var = False
        else:
            collection.insert(0)
            state_var = True
    return collection
for thing in make_collection():
    print(thing)