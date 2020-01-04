# Lexical Analyzer
# Coded by Shubham aka ner0
# https://github.com/real-ner0


# Take source code file name as input
file_name = input("Enter file to analyze...")

# Open source code in read mode
source_code = open(file_name, 'r')

# LOC Count
line_count = 0

# 'set()' to avoid duplicancy
identifiers = set()
operators_set = set()
constants = set()
symbols_set = set()
tokens_set = set()

symbols = ['!','#','(',')','_','{','}','[',']','\\',':',';','\'','\"',',','.','?']
operators = ['+','-','/','*','%','//','**','>','<','==','!=','! =','>=','> =','<=','< =','&','|','~','^','>>','<<','=','+=','+ =','-=','- =','*=','* =','/=','/ =','%=','% =','//=','// =']
keywords = ['range','print','False','None','True','and','as','assert','break','class','continue','def','del','elif','else','else:','else :','except','finally','for','from','global','if','import','in','is','lambda','nonlocal','not','or','pass','raise','return','try','while','with','yield']

code = source_code.read()
loc = code.split('\n')

for line in loc:
    line_count += 1
    tokens = line.split(' ')
    for token in tokens:
        if token in symbols:
            symbols_set.add(token)
        elif token in keywords:
            tokens_set.add(token)
        elif token in operators:
            operators_set.add(token)
        elif token.isnumeric():
            constants.add(token)
        else:
            identifiers.add(token)


print("Number of lines ", line_count)
print("The Keywords are ", tokens_set)
print("The Variables are ", identifiers)
print("The Symbols are ", symbols_set)
print("The Operators are ", operators_set)
