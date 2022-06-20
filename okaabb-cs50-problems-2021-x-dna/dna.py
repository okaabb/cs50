from cs50 import get_string
import csv
import sys


def main():
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")
    else:
        data = []
        if sys.argv[1] == "databases/small.csv":
            with open(sys.argv[1]) as file:
                reader = csv.DictReader(file)
                for row in reader:
                    row['AGATC'] = int(row['AGATC'])
                    row['AATG'] = int(row['AATG'])
                    row['TATC'] = int(row['TATC'])
                    data.append(row)
            f = open(sys.argv[2], 'r')
            DNA = f.read()
            first = agatc(DNA)
            second = aatg(DNA)
            third = tatc(DNA)
        
            ans = 0
            for i in data:
                if i['AGATC'] == first and i['AATG'] == second and i['TATC'] == third:
                    ans = i['name']
                
            if ans == 0:
                print("No match")
            else:
                print(f"{ans}")
            
        else:
            data = []
            if sys.argv[1] == "databases/large.csv":
                with open(sys.argv[1]) as file:
                    reader = csv.DictReader(file)
                    for row in reader:
                        row['AGATC'] = int(row['AGATC'])
                        row['TTTTTTCT'] = int(row['TTTTTTCT'])
                        row['AATG'] = int(row['AATG'])
                        row['TCTAG'] = int(row['TCTAG'])
                        row['GATA'] = int(row['GATA'])
                        row['TATC'] = int(row['TATC'])
                        row['GAAA'] = int(row['GAAA'])
                        row['TCTG'] = int(row['TCTG'])
                        data.append(row)
            f = open(sys.argv[2], 'r')
            DNA = f.read()
            one = agatc(DNA)
            two = ttttttct(DNA)
            three = aatg(DNA)
            four = tctag(DNA)
            five = gata(DNA)
            six = tatc(DNA)
            seven = gaaa(DNA)
            eight = tctg(DNA)

            ans = 0
            for i in data:
                if i['AGATC'] == one and i['TTTTTTCT'] == two and i['AATG'] == three and i['TCTAG'] == four and i['GATA'] == five and i['TATC'] == six and i['GAAA'] == seven and i['TCTG'] == eight:
                    ans = i['name']
                
            if ans == 0:
                print("No match")
            else:
                print(f"{ans}")
        
        
def aatg(DNA):
    cnt = 0
    seq = []
    for i in range(0, len(DNA)-1):
        cnt = 0
        if DNA[i] == 'A':
            ii = i
            a = ii + 1
            b = ii + 2
            c = ii + 3
            if c < len(DNA)-1:
                while DNA[ii] == 'A' and DNA[a] == 'A' and DNA[b] == 'T' and DNA[c] == 'G' and c < len(DNA)-1:
                    cnt += 1
                    ii += 4
                    a = ii + 1
                    b = ii + 2
                    c = ii + 3
                seq.append(cnt)    
            
    return max(seq)


def tatc(DNA):
    cnt = 0
    seq = []
    for i in range(0, len(DNA)-1):
        cnt = 0
        if DNA[i] == 'T':
            ii = i
            a = ii + 1
            b = ii + 2
            c = ii + 3
            if c < len(DNA)-1:
                while DNA[ii] == 'T' and DNA[a] == 'A' and DNA[b] == 'T' and DNA[c] == 'C' and c < len(DNA)-1:
                    cnt += 1
                    ii += 4
                    a = ii + 1
                    b = ii + 2
                    c = ii + 3
                seq.append(cnt)  
            
    return max(seq)
    
    
def agatc(DNA):
    cnt = 0
    seq = []
    for i in range(0, len(DNA)-1):
        cnt = 0
        if DNA[i] == 'A':
            ii = i
            a = i + 1
            b = i + 2
            c = i + 3
            d = i + 4
            if d < len(DNA)-1:
                while DNA[i] == 'A' and DNA[a] == 'G' and DNA[b] == 'A' and DNA[c] == 'T' and DNA[d] == 'C' and d < len(DNA)-1:
                    cnt += 1
                    ii += 5
                    a = ii + 1
                    b = ii + 2
                    c = ii + 3
                    d = ii + 4
                seq.append(cnt)
            
    return max(seq)    


def ttttttct(DNA):
    cnt = 0
    seq = []
    for i in range(0, len(DNA)-1):
        cnt = 0
        if DNA[i] == 'T':
            ii = i
            a = ii + 1
            b = ii + 2
            c = ii + 3
            d = ii + 4
            e = ii + 5
            f = ii + 6
            g = ii + 7
            if g < len(DNA)-1:
                while DNA[ii] == 'T' and DNA[a] == 'T' and DNA[b] == 'T' and DNA[c] == 'T' and DNA[d] == 'T' and g < len(DNA)-1 and DNA[e] == 'T' and DNA[f] == 'C' and DNA[g] == 'T':
                    cnt += 1
                    ii += 8
                    a = ii + 1
                    b = ii + 2
                    c = ii + 3
                    d = ii + 4
                    e = ii + 5
                    f = ii + 6
                    g = ii + 7
                seq.append(cnt)  
    return max(seq)
    

def tctag(DNA):
    cnt = 0
    seq = []
    for i in range(0, len(DNA)-1):
        cnt = 0
        if DNA[i] == 'T':
            ii = i
            a = ii + 1
            b = ii + 2
            c = ii + 3
            d = ii + 4
            if d < len(DNA)-1:
                while DNA[ii] == 'T' and DNA[a] == 'C' and DNA[b] == 'T' and DNA[c] == 'A' and DNA[d] == 'G' and d < len(DNA)-1:
                    cnt += 1
                    ii += 5
                    a = ii + 1
                    b = ii + 2
                    c = ii + 3
                    d = ii + 4
                seq.append(cnt)  
            
    return max(seq)
    
    
def gata(DNA):
    cnt = 0
    seq = []
    for i in range(0, len(DNA)-1):
        cnt = 0
        if DNA[i] == 'G':
            ii = i
            a = ii + 1
            b = ii + 2
            c = ii + 3
            if c < len(DNA)-1:
                while DNA[ii] == 'G' and DNA[a] == 'A' and DNA[b] == 'T' and DNA[c] == 'A' and c < len(DNA)-1:
                    cnt += 1
                    ii += 4
                    a = ii + 1
                    b = ii + 2
                    c = ii + 3
                seq.append(cnt)  
            
    return max(seq)
    
    
def gaaa(DNA):
    cnt = 0
    seq = []
    for i in range(0, len(DNA)-1):
        cnt = 0
        if DNA[i] == 'G':
            ii = i
            a = ii + 1
            b = i + 2
            c = ii + 3
            if c < len(DNA)-1:
                while DNA[ii] == 'G' and DNA[a] == 'A' and DNA[b] == 'A' and DNA[c] == 'A' and c < len(DNA)-1:
                    cnt += 1
                    ii += 4
                    a = ii + 1
                    b = ii + 2
                    c = ii + 3
                seq.append(cnt)  
            
    return max(seq)
    
    
def tctg(DNA):
    cnt = 0
    seq = []
    for i in range(0, len(DNA)-1):
       # print(f"{i},{cnt}")
        if DNA[i] == 'T':
            ii = i
            a = ii + 1
            b = ii + 2
            c = ii + 3
            if c < len(DNA)-1:
                while True:
                    if DNA[ii] == 'T' and DNA[a] == 'C' and DNA[b] == 'T' and DNA[c] == 'G' and c < len(DNA)-1:
                        cnt += 1
                        ii += 4
                        a = (ii + 1)
                        b = (ii + 2)
                        c = (ii + 3)
                    else:
                        seq.append(cnt) 
                        cnt = 0
                        a = 0 
                        b = 0
                        c = 0
                        break
                
    return max(seq)

        
main()