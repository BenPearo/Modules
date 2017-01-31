default:

clean:
	rm ./a.out

git:
	git add * && git status && git commit && git status && git push && git status
