
## Title: Law of Large Numbers
## Author: Luca La Rocca
## Date: 4 November 2024

## Sys.setLanguage("en", unset="it") # uncomment to disable message translation
rm(list=ls(all=TRUE)) # clean the workspace

m <- 2500 # size of simulations
n <- 12 # number of Bernoulli trials
p <- 1/6 # success probability
g <- 100 # number of terms to keep when approximating Geom(p)

cat("Sampling m =", m, "observations from a binomial distribution", fill=TRUE)
cat("with n =", n, "and p =", p, "gives...", fill=TRUE)
x <- rbinom(m, n, p)
cat("...an empirical mean equal to", mean(x),
    "with margin of error", 2*sd(x)/sqrt(length(x)), fill=TRUE)

pdf("Rfig12indepdraws.pdf", width=8, height=5)
plot(1:m, x, type="l", ylim=c(0, 12))
title(main=paste("Independent draws from Binom(n=", n,",p=", round(p, 4), ")",
                 sep=""))
dev.off()

pdf("Rfig12runningmean.pdf", width=8, height=5)
plot(1:m, cumsum(x)/1:m, type="l", ylim=c(0, 12), ylab=expression(bar(x)))
title(main=paste("Running mean from Binom(n=", n, ",p=", round(p, 4), ")",
                 sep=""))
abline(h=n*p, col=gray(0.75))
dev.off()

cat("Sampling m =", m, "observations from a geometric distribution", fill=TRUE)
cat("with p =", p, "gives...", fill=TRUE)
y <- rgeom(m, p)
cat("...an empirical mean equal to", mean(y),
    "with margin of error", 2*sd(y)/sqrt(length(y)), fill=TRUE)
cat("whereas the population mean is", (1-p)/p,
    "or approximately", sum(0:(g-1)*dgeom(0:(g-1), p)),
    "(adding", g, "terms)", fill=TRUE)

plot(1:m, cumsum(2^(y+1))/1:m, type="l", ylab=expression(bar(x)))
title(main=paste("Running mean from the St. Petersburg paradox"))