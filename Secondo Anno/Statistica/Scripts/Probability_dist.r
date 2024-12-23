
## Title: Estimating probability distributions
## Author: Luca La Rocca
## Date: 25 November 2024

## Sys.setLanguage("en", unset="it") # uncomment to disable message translation
rm(list=ls(all=TRUE)) # clean the workspace
simsize <- 10000 # size of all simulations

## The "empirical rule" for standard normal variables
cat("For a standard normal variable Z:", fill=TRUE)

cat("Pr(|Z|<1) = Pr(-1<Z<+1) =", round(mean(abs(rnorm(simsize))<1),1),
    "(simulated)", fill=TRUE)
cat("Pr(|Z|<1) = Pr(-1<Z<+1) =", round(2*pnorm(1)-1,1), "(exact)", fill=TRUE)

cat("Pr(|Z|<2) = Pr(-2<Z<+2) =", round(mean(abs(rnorm(simsize))<2),2),
    "(simulated)", fill=TRUE)
cat("Pr(|Z|<2) = Pr(-2<Z<+2) =", round(2*pnorm(2)-1,2), "(exact)", fill=TRUE)

cat("Pr(|Z|<3) = Pr(-3<Z<+3) =", round(mean(abs(rnorm(simsize))<3),3),
    "(simulated)", fill=TRUE)
cat("Pr(|Z|<3) = Pr(-3<Z<+3) =", round(2*pnorm(3)-1,3), "(exact)", fill=TRUE)

## Die Rolls
## sum of dice with a given number of sides
DRdice <- 3 # number of dice
DRsides <- 4 # number of sides of each die

DRsum <- replicate(simsize, {
  roll <- sample(1:DRsides, DRdice, replace = TRUE)
  sum(roll)
}) # end of replicate

DRpmf <- proportions(table(DRsum))
print(DRpmf)

pdf("Rfig17dieRolls.pdf", width=8, height=5)
plot(DRpmf, bty="n",
     xlab="Total score (sum of scores)", ylab="Probability",
     main=paste(DRdice, "dice with", DRsides, "sides"))
plot(ecdf(DRsum))
dev.off()

## Birthday Problem
## number of people sharing a birthday
BPhowmany <- 23 # people in a room

BPpeopleSharing <- replicate(simsize, {
  birthdays <- sample(1:365, BPhowmany, replace=TRUE)
  birthcounts <- table(birthdays)
  sum(birthcounts[birthcounts>1])
}) # end of replicate

BPpmf <- proportions(table(BPpeopleSharing))
print(BPpmf)

pdf("Rfig17bdayProblem.pdf", width=8, height=5)
plot(BPpmf, bty="n",
     xlab="Number of people sharing a birthday", ylab="Probability",
     main=paste(BPhowmany, "people in a room"))
plot(ecdf(BPpeopleSharing))
dev.off()

## Birthday Special
## number of people sharing my birthday
BShowmany <- 253 # people in a room (including me)

BSpeopleSharing <- replicate(simsize, {
  birthdays <- sample(1:365, BShowmany, replace=TRUE)
  sum(birthdays[-1]==birthdays[1])
}) # end of replicate

BSpmf <- proportions(table(BSpeopleSharing))
print(BSpmf)

pdf("Rfig17bdaySpecial.pdf", width=8, height=5)
plot(BSpmf, bty="n",
     xlab="Number of people sharing my birthday", ylab="Probability",
     main=paste(BShowmany, "people in a room (including me)"))
plot(ecdf(BSpeopleSharing))
dev.off()

## Coin Flips
## number of times head is ahead of tail in a finite number of coin flips
CFhowmany <- 20 # number of coin flips

CFtimesHahead <- replicate(simsize, {
  flips <- sample(c("H", "T"), CFhowmany, replace=TRUE)
  cumheads <- cumsum(flips=="H")
  cumtails <- cumsum(flips=="T")
  sum(cumheads>cumtails)
}) # end of replicate

CFpmf <- proportions(table(CFtimesHahead))
print(CFpmf)

pdf("Rfig17coinFlips.pdf", width=8, height=5)
plot(CFpmf, bty="n",
     xlab = "Times Head is ahead of Tail", ylab = "Probability",
     main=paste(CFhowmany, "coin flips"))
plot(ecdf(CFtimesHahead))
dev.off()

## Random Walk
## first return time in a random walk with finitely many steps available
RWsteps <- 10 # number of leftward and rightward steps available

RWreturnTime <- replicate(simsize, {
  movements <- sample(rep(c(1, -1), times=RWsteps), 2*RWsteps, replace=FALSE)
  min(which(cumsum(movements)==0))
}) # end of replicate

RWpmf <- proportions(table(RWreturnTime))
print(RWpmf)

pdf("Rfig17randomWalk.pdf", width=8, height=5)
plot(RWpmf, bty="n", xlab="First return time (steps)", ylab="Probability",
     main=paste(2*RWsteps, "step random walk"))
plot(ecdf(RWreturnTime))
dev.off()

## Ballot Theorem
## probability of winner always ahead throughout the count
BTwinvotes <- 15 # number of votes for the winner
BTlosvotes <- 10 # number of votes for the loser

BTalwaysahead <- replicate(simsize, {
  movements <- sample(rep(c(1, -1), times=c(BTwinvotes, BTlosvotes)),
                      BTwinvotes+BTlosvotes, replace=FALSE)
  all(cumsum(movements)>0)
}) # end of replicate

BTempiprop <- mean(BTalwaysahead)
BTteorprob <- (BTwinvotes-BTlosvotes)/(BTwinvotes+BTlosvotes)

cat("Probability of winner always ahead throughout the count:", fill=TRUE)
print(BTempiprop)
cat("Does it equal the probability given by the ballot theorem?", fill=TRUE)
print(all.equal(BTteorprob, BTempiprop, scale=1))