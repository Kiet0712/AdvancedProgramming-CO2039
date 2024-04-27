data_set = [False,True,False,True]
collection = []
i = 1
for datum in data_set:
    if datum:
        collection.append(i)
    else:
        collection.append(i+1)