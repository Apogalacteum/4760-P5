oss: Project4Main.c
	gcc Project4Main.c -o oss

userP: Project4UserP.c
	gcc Project4UserP.c -o userP

clean:
	rm oss
	rm userP
