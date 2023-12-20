# Online Python Playground
# Use the online IDE to write, edit & run your Python code
# Create, edit & delete files online

def getOverlappingIndex(text,seq):
    lps = [0] * len(seq)
    length = 0
    i = 1
    
    while i < len(seq):
        if seq[i] == seq[length]:
            lps[i] = length + 1
            length += 1
            i += 1
        else:
            if length != 0:
                length = lps[length-1]
            else:
                lps[i] = 0
                i += 1
    
    return lps            
    
def stringmatching(text,pat):
    N = len(text)
    M = len(pat)
    
    i = 0
    j = 0
    
    overlapArr = getOverlappingIndex(text,pat)
    while i < N:
        if text[i] == pat[j]:
            i += 1
            j += 1
        else:
            if j != 0:
                j = overlapArr[j-1]
            else:
                i += 1
        
        if j == M:
            print(i-j)
            j = overlapArr[j-1]
            
stringmatching("onionionsioxyzonionsonionsio","onionsio")
