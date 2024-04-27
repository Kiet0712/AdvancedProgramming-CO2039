data_set = [False,True,False,True]
i = 1
collection = [i if datum else i+1 for datum in data_set]