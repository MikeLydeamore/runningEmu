bigM <- 1e6
m <- matrix(rnorm(bigM), nrow=as.integer(sqrt(bigM)))
bench::mark(un(m), iterations = 10)

bench::mark(un_test(m), iterations = 150)

un_test(m)
un(m)


vv <- sample(1:10, bigM, replace=TRUE, prob=sample(seq(0.1,0.9,by=0.1), 10, replace = TRUE))
bench::mark(trois(vv), iterations = 10)
bench::mark(trois_test2(vv), iterations = 25)
bench::mark(trois_test(vv), iterations = 25)
bench::mark(count_occurrences(vv), iterations = 25)

trois(vv)

trois_test2(vv)

trois_test(vv)

count_occurrences(vv)
