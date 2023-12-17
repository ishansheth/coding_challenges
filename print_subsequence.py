
def print_subset(values):
    x = [ i for i in values if i != -1]
    print(x)


def helper(values,subset,i):
    if i == len(values):
        print_subset(subset)
    else:
        subset[i] = -1
        helper(values,subset,i+1)
        subset[i] = values[i]
        helper(values,subset,i+1)
        
def generate_subsets(values):
    subset = [-1]*len(values)
    helper(values,subset,0)
    
    
generate_subsets([1,2])
