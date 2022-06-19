##
# DAA Assignment 234
#
# @file
# @version 0.1


SRN=PES2UG20CS214

all: a.out

a.out: $(SRN).o client.o
	$(CC) $(SRN).o client.o

client.o: client.c
	$(CC) -c client.c

$(SRN).o: $(SRN).c
	$(CC) -c -Wall -pedantic $(SRN).c

.PHONEY: clean

clean:
	rm client.o $(SRN).o a.out

# end
