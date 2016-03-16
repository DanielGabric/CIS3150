
dom = [["ab","abab"],["b","a"],["aba","b"],["aa","a"]]
L = [-1 for i in range(8)]
def recurse(n):
    if n < 8:
        if n > 0:
            str1 = "."
            str2 = "."
            str3 = " "
            str4 = " "
            for i in xrange(n):
                str1 += dom[L[i]][0]
                str2 += dom[L[i]][1]
                str3 += dom[L[i]][0]+" "
                str4 += dom[L[i]][1]+" "
            if str1 == str2:
                print L
                print str3
                print str4



        for i in xrange(4):
            L[n]=i
            recurse(n+1)

recurse(0)