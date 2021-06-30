from copy import deepcopy
from queue import LifoQueue
from collections import deque
import json
Nonterminals = ["E", "Edash", "T", "Tdash", "F"]
terminals = ["+", "*", "(", ")", "id", "$"]

table = list()


E, T, F = (["(", "id"], ) * 3
Edash = ["+", "$", ")"]
Tdash = ["+", "$", ")", "*"]
print(globals()["Edash"])


Productions = dict()
Productions = {"E": ["T_Edash"], "Edash": ["+_T_Edash", "epsilon"],
               "T": ["F_Tdash"], "Tdash": ["*_F_Tdash", "epsilon"], "F": ["(E)", "id"]}


for i in Nonterminals:

    for j in terminals:
        info = {}
        if j in globals()[i]:
            if "epsilon" not in Productions[i]:
                info[i+'_'+j] = Productions[i][0]
                print(info[i+'_'+j], i+'_'+j)
            else:
                if (j == ")" or j == "$") or (j == "+" and i == "Tdash"):
                    info[i+'_'+j] = "epsilon"
                    print(info[i+'_'+j], i+'_'+j)
                elif (j == "*" and i == "Tdash") or (j == "+" and i == "Edash"):
                    info[i+'_'+j] = Productions[i][0]
                    print(info[i+'_'+j], i+'_'+j)
            info1 = info.copy()
            table.append(deepcopy(info))

table[12]["F_id"] = "id"
print(table)
print("\n\n")

string = input("Enter the input:")
print(string)
str = list()
while(len(string)):
    print(len(string))
    t = string.find('id')
    if(t == 0):
        str.append('id')
        string = string[t+2:]
    else:
        t=1
        str.extend(list(string[0:t]))
        string = string[t:]
i = 0
keys_list = [value for elem in table for value in elem.keys()]
str.append('$')
print(keys_list)


stack = deque()
stack.append("E")
while(len(stack) > 0):
    t = stack[-1]
    print(t,str[0])
    print(str)
    print(stack)
    #stack.put(t)
    if t == str[0]:
        str.pop(0)
        stack.pop()
    elif (t in terminals or  str[0] not  in terminals):
        print("string rejected")
        exit()
    elif t in Nonterminals:
        if t +'_'+str[0] not in keys_list:
            print("Error")
            exit()
        if (table[keys_list.index(t +'_'+str[0])][t +'_'+str[0]] == "epsilon"):
            stack.pop()
        else:
            stack.pop()
            [stack.append(val) for val in reversed(table[keys_list.index(t +'_'+str[0])][t +'_'+str[0]].split('_'))]
    else:
        print("string rejected")
        exit()

if len(stack) == 0:
    print("string accepted")
else:
    print("String rejected")
