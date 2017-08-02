l = []

for i in range(1, 101):
	if i % 3 == 0:
		l.append("Fizz")
	else:
		l.append(i)

print l 

print ["Fizz" if i % 3 == 0 else i for i in range(1, 101)] 