import sys
def main():
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")
    else:
        
        f = open(sys.argv[2], 'r')
        dna = f.read()
        for i in range(0, len(dna)-1):
           # print(dna[i])
            i+=1
            print(dna[i])
        
        
main()