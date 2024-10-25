
## Title: Stochastic simulations
## Author: Luca La Rocca
## Date: 1 October 2024

## Sys.setLanguage("en", unset="it") # uncomment to disable message translation
rm(list=ls(all=TRUE)) # clean the workspace

ls(all=TRUE) # empty workspace

sample(1:6,1) # 1d6 or single extraction from an urn with six numbered balls
sample(1:6,3) # three extractions without replacement from that urn
sample(1:6,6) # random permutation of the balls in that urn
try(sample(1:6,7)) # impossible
sample(1:6,7, replace=TRUE) # possible
sample(1:6,3, replace=TRUE) # 3d6 or three extractions with replacement

ls(all=TRUE) # hidden RNG state

d6size <- 1000 # sample size for simulation
d6samp <- sample(1:6, d6size, replace=TRUE)
d6six <- d6samp==6
plot(1:d6size, cumsum(d6six)/1:d6size, type="l", ylim=c(0,1),
     xlab = expression(n), ylab=expression(p[n]), main="Bernoulli's theorem")
abline(h=1/6, lty="dashed")

bloodtypes <- c("A", "AB", "B", "O") # in alphabetical order
bloodprobs <- c(0.40, 0.04, 0.11, 0.45) # need not sum to one
bloodsize <- 1000 # sample size for simulation
bloodsamp <- sample(bloodtypes, bloodsize, prob=bloodprobs,
                    replace=TRUE) # order of named arguments doesn't matter
bloodprop <- proportions(table(bloodsamp))
cat("When comparing a sample proportion to a population probability", fill=TRUE)
cat("based on a sample of size n =", bloodsize, fill=TRUE)
cat("we are confident that the difference will not exceed 1/sqrt(n) =",
    1/sqrt(bloodsize), fill=TRUE)
cat("and in the present case (blood types in the United States)", fill=TRUE)
print(all.equal(bloodprobs, as.vector(bloodprop), scale=1))

birthdayStudents <- 22 # number of students in the classroom (plus one teacher)
cat("The probability of at least two coinciding birthdays", fill=TRUE)
cat("among", birthdayStudents,"students plus one teacher is", fill=TRUE)
birthdayCoincidence <- replicate(10000,{
  birthdays <- sample(1:365, birthdayStudents+1, replace=TRUE)
  anyDuplicated(birthdays)>0
}) # end of replicate
cat("approximately", mean(birthdayCoincidence),
    "and exactly", 1-prod(365:(365-birthdayStudents))/365^(birthdayStudents+1),
    fill=TRUE)
cat("The probability of at least a birthday coinciding with", fill=TRUE)
cat("the teacher's birthday among", birthdayStudents,"students is", fill=TRUE)
birthdayTeacher <- replicate(10000,{
  teacherday <- sample(1:365, 1)
  birthdays <- sample(1:365, birthdayStudents, replace=TRUE)
  any(birthdays==teacherday)
}) # end of replicate
cat("approximately", mean(birthdayTeacher),
    "and exactly", 1-(364/365)^birthdayStudents,
    fill=TRUE)

LottoNumeri <- c(9,81) # to fix ideas
cat("The probability of \"ambo secco\" is", fill=TRUE)
LottoAmbo <- replicate(100000,{
  estratti <- sample(1:90, 5)
  all(LottoNumeri %in% estratti)
}) # end of replicate
LottoEmpirP <- mean(LottoAmbo)
LottoTheorP <- prod(c(5,4,88,87,86))/prod(90:86)
cat("approximately", LottoEmpirP, "and exactly p =", LottoTheorP, fill=TRUE)
cat("so that a fair payment for a 1 euro bet would be 1/p =",
    1/LottoTheorP, "euro", fill=TRUE)
cat("whereas the actual payment is 250 euro (minus taxes)", fill=TRUE)

seme <- function(carta) # an integer between 1 and 40
{c("Coppe", "Denari", "Bastoni", "Spade")[(carta-1)%/%10+1]}
valore <- function(carta) # an integer between 1 and 40
{(carta-1)%%10+1}
cat("The probability of two Italian cards having the same suit or value is",
    fill=TRUE)
carteEvento <- replicate(40000,{
  mano <- sample(1:40, 2)
  anyDuplicated(seme(mano))>0 | anyDuplicated(valore(mano))>0
}) # end of replicate
cat("approximately", mean(carteEvento),
    "and exactly", (40*9)/(40*39)+(40*3)/(40*39),
    fill=TRUE)

cat("The probability of forming a triangle when breaking a stick", fill=TRUE)
cat("in two (uniformly chosen) random points is ")
stickTriangle <- replicate(10000,{
  stickbreaks <- sort(runif(2))
  sticklengths <- sort(diff(c(0, stickbreaks, 1)))
  sum(sticklengths[1:2]) > sticklengths[3]
}) # end of replicate
cat("approximately", mean(stickTriangle), fill=TRUE)

RisikoAsize <- 5
RisikoDsize <- 3
cat("The probability of winning a no-tomorrow Risiko attack", fill=TRUE)
cat("using", RisikoAsize, "armies against", RisikoDsize, "defending armies is ")
RisikoAwins <- replicate(10000,{
  Attackers <- RisikoAsize
  Defenders <- RisikoDsize
  while(Attackers > 0 & Defenders > 0)
  {
    a <- min(Attackers, 3)
    d <- min(Defenders, 3)
    attack <- sort(sample(1:6, a, rep = TRUE), decreasing = TRUE)
    defend <- sort(sample(1:6, d, rep = TRUE), decreasing = TRUE)
    m <- min(a, d)
    losses <- sum(attack[1:m]<=defend[1:m])
    Attackers <- Attackers - losses
    Defenders <- Defenders - (m - losses)
  }
  Defenders == 0
}) # end of replicate
cat("approximately", mean(RisikoAwins), fill=TRUE)
