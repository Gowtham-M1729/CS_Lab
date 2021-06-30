from copy import deepcopy
from collections import deque

Nonterminals = ["E", "Edash", "T", "Tdash", "F"]
terminals = ["+", "*", "(", ")", "id", "$"]

table = list()

#E,T,F indicates first of E,T,F respectively
E, T, F = (["(", "id"], ) * 3

#Edash and Tdash contains the union of both first and follow of Edash and Tdash
Edash = ["+","$", ")"]
Tdash = ["+", "$", ")", "*"]


#Productions is a dictonary which contains the productions of all non terminals
Productions = {"E": ["T_Edash"], "Edash": ["+_T_Edash", "epsilon"],
               "T": ["F_Tdash"], "Tdash": ["*_F_Tdash", "epsilon"], "F": ["(E)", "id"]}


#below code is used to fill the table
for i in Nonterminals:
    for j in terminals:
        info = {}
        if j in globals()[i]:
            if "epsilon" not in Productions[i]:
                info[i+'_'+j] = Productions[i][0]
            else:
                if (j == ")" or j == "$") or (j == "+" and i == "Tdash"):
                    info[i+'_'+j] = "epsilon"
                elif (j == "*" and i == "Tdash") or (j == "+" and i == "Edash"):
                    info[i+'_'+j] = Productions[i][0]
            info1 = info.copy()
            table.append(deepcopy(info))

table[12]["F_id"] = "id"
#print(table)
print("\n\n")

#To store all the locations of a table that contains the production
keys_list = [value for elem in table for value in elem.keys()]
#print(keys_list)

print("\n\n")
l = []
for i in Nonterminals:
    ll =[]
    for j in terminals:
        if i+"_"+j in keys_list:
            ll.append(table[keys_list.index(i +'_'+ j)][i +'_'+j]+"|")
        else:
            ll.append(" "+"|")
    l.append(ll)

print("PREDICTIVE PARSING TABLE".center(70),end = "\n\n")
format_row = "{:>12}" * (len(terminals) + 1)
print(format_row.format("", *terminals))

print("-------------------------------------------------------------------------------------")
for team, row in zip(Nonterminals, l):
    print(format_row.format(team, *row))
    print("-------------------------------------------------------------------------------------")

string = input("\n\nEnter the input:")



str = list()
#below code converts the input string to list of strings
while(len(string)):
    t = string.find('id')
    if(t == 0):
        str.append('id')
        string = string[t+2:]
    else:
        t=1
        str.extend(list(string[0:t]))
        string = string[t:]

str.append("$")
print(str)


i = 0
print("\n\n")
stack = deque()
stack.append("E")#storing start symbol in stack

print("input string:","".join(str),end="\n\n")
print("E".center(15))
print("|____________|")
print("\n\n")

#string parsing algorithm
while(len(stack) > 0):
    t = stack[-1]
    #print("stack:",stack)

    #if both TOS and input string contains same terminal and are equal ,then pop
    if t == str[0]:
        str.pop(0)
        stack.pop()
    #if both TOS and input string contains same terminal and are not equal,string is rejected
    elif(t in terminals and str[0] in terminals) and (t != str[0]):
        print("string rejected")
        exit()
    #if TOS is a non terminal
    elif t in Nonterminals:
        print(t +'_'+str[0])
        
        print("input string:","".join(str),end="\n\n")
        #to check if the table is filled for the current location(TOS on input string)
        if t +'_'+str[0] not in keys_list:
            print("******String rejected*******")
            exit()
        #if cell of the table doesn't contain epsilon,then pop from stack and then push its production
        if((table[keys_list.index(t +'_'+str[0])][t +'_'+str[0]] != "epsilon") ):
            stack.pop()
            [stack.append(val) for val in reversed(table[keys_list.index(t +'_'+str[0])][t +'_'+str[0]].split('_'))]
        else:
            stack.pop()
    else:
        print("********String rejected*******")
        exit()
    #print("stack:",list(reversed(stack)),end = "\n\n")
    for i in list(reversed(stack)):
        #print()
        print(i.center(15))
        print("|____________|")
    print("\n\n")

if len(stack) == 0:
    print("*****String accepted*******")
else:
    print("********String rejected*********")
