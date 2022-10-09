ones = ["", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine "]
elevens = ["Ten ", "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen "]
tens = ["", "", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety "]
others = ["", "Thousand ", "Million ", "Billion ", "Trillion ", "Hundred "]

def number_places(num, places=""):
    n1 = int(num[0])
    n2 = int(num[1])
    n3 = int(num[2])
    if n1 == 0:
        if n2 == 1:
            return f"{elevens[n3]}{places}"
        elif n2 == 0 and n3 == 0:
            return ""
        else:
            return f"{tens[n2]}{ones[n3]}{places}"
    elif n2 == 1:
        return f"{ones[n1]}{others[-1]}{elevens[n3]}{places}"
    else:
        return f"{ones[n1]}{others[-1]}{tens[n2]}{ones[n3]}{places}"


t = int(input())
for a0 in range(t):
    number = input()

    if int(number) > 0:
        length = len(number)
        if length%3 == 1:
            number = "00"+number
        elif length%3 == 2:
            number = "0"+number
        b = 0 #take starting position in others list
        c = -1 #iterate the others list
        result = "" #final result after loop
        length = len(number)
        for i in range(length):
            if (length-i)%3 == 0:
                c += 1
                if length == 15:
                    b = others[4-c]
                elif length == 12:
                    b = others[3-c]
                elif length == 9:
                    b = others[2-c]
                elif length == 6:
                    b = others[1-c]
                elif length == 3:
                    b = ""
                num1 = number[i] + number[i+1] + number[i+2]
                num_word = number_places(num=num1, places=b)
                result += num_word
        print(result)
    else:
        print("Zero")
