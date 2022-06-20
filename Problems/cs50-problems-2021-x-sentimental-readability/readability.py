from cs50 import get_string


def main():
    text = get_string("Enter text: ")
    letters = 0
    words = 0
    sentences = 0
    
    for i in text:
        if i >= 'a' and i <= 'z' or i >= 'A' and i <= 'Z':
            letters += 1
        elif i == '!' or i == '?' or i == '.':
            sentences += 1
        elif i == ' ':
            words += 1
    words += 1        
    L = (100 * letters) / words
    S = (100 * sentences) / words
    ans = (0.0588 * L) - (0.296 * S) - 15.8
    if ans < 1:
        print("Before Grade 1")
    elif ans >= 16:
        print("Grade 16+")
    else:
        temp = (ans - int(ans)) * 10
        if temp >= 5:
            ans += 1
        print(f"Grade {int(ans)}")
    
    
main()