## Title: Data in R
## Author: Luca La Rocca
## Date: 24 September 2024
## install.packages("HistData") # install the package HistData
library(HistData) # load a collection of historical datasets
## Sys.setLanguage("en", unset="it") # uncomment to disable message translation
rm(list = ls(all = TRUE)) # clean the workspace

## a classical beginning
cat("Hello World!", fill = TRUE)

## R as a calculator (?Arithmetic)
2 + 3 # = 5
2 - 3 # = -1
2 * 3 # = 6
2^3 # = 8
2 / 3 # = 0.6666667 (rounded to seven significant digits)
2 %/% 3 # = 0
2 %% 3 # 2

## R as a scientific calculator
cat("The circumference to diameter ratio is", pi, fill = TRUE)
cat("Thirty degrees are", pi / 6, "radiants", fill = TRUE)
cat("The sine of a thirty degree angle is", sin(pi / 6), fill = TRUE)
cat("The arc sin of one half is", asin(1 / 2), "radiants", fill = TRUE)

cat("Euler's number is", exp(1), fill = TRUE)
cat("The natural logarithm of eight is", log(8), fill = TRUE)
cat("The common logarithm of one hundred is", log(100, base = 10), fill = TRUE)
cat("The binary logarithm of sixteen is", log2(x = 16), fill = TRUE)

## R as a calculator with memory
x <- 2 # assignment
x == 3 # comparison
x # show the value of "x" (when sourcing the script with echo)
y <- 4 # recommended assignment
5 -> y # rightwards assignment
x + y # = 7
z <- x / y
cat("Object \"z\" has the following structure:", fill = TRUE)
str(z)

## Where are R objects?
ls() # list user defined objects (workspace contents)
pi <- 1 / 2 # mask the homonymous built-in object (bad idea)
ls() # now "pi" is a user defined object
cat("The probability of getting head when tossing a coin is", pi, fill = TRUE)
cat("The circumference to diameter ratio is still", base::pi, fill = TRUE)
search() # give the search path for R objects (workspace first)
rm(pi) # removes object "pi" from the workspace
ls() # now "pi" is again the buit-in object

## Beware of hidden objects!
initials <- sample(LETTERS, 4)
cat("Object \"initials\" has the following structure:", fill = TRUE)
str(initials)
ls(all = TRUE) # a hidden state for random number generation has been added

## several ways to build vectors
truthvalues <- c(FALSE, TRUE) # better not use built-in objects F and T
cat("Object \"truthvalues\" has the following structure:", fill = TRUE)
str(truthvalues)

rep(truthvalues, times = 3) # repeat whole vector three times
rep(truthvalues, times = c(3, 5)) # repeat FALSE three times and TRUE five times
rep(truthvalues, each = 3) # repeat each entry three times
rep(truthvalues, length = 5) # cyclically repeat entries to obtain five values

firstsix <- 1:6
cat("Object \"firstsix\" has the following structure:", fill = TRUE)
str(firstsix)

seq(1, 12, by = 2) # odd numbers
seq(1, 12, length = 6) # six equispaced values from one to twelve

## vectorized operators
firstsix^2 # squares of first six natural numbers
1 / firstsix # reciprocals of first six natural numbers
firstsix + 10 # first six natural numbers after ten

## vectorized functions
sqrt(firstsix) # square roots of first six natural numbers
plot(firstsix, exp(firstsix),
    pch = "+", type = "b", col = "red",
    xlab = "x", ylab = "exp(x)", main = "A plot of the exponential function"
)

## plotting to file
getwd() # check working directory
pdf("Rfig02expfun.pdf")
curve(exp,
    from = 1, to = 6, col = "red",
    main = "A better plot of the exponential function"
)
dev.off()

## vector summaries
sum(firstsix)
mean(firstsix)
min(firstsix)
max(firstsix)

## indexing vectors with integer values
letters[2] # extract second entry
letters[c(1, 5, 9, 15, 21)] # extract vowel entries
letters[-c(1, 5, 9, 15, 21)] # extract consonant entries
letters[1:13] # extract first thirteen entries

## indexing vectors with logical vales
letters[rep(truthvalues, length = 26)] # extract entries in even position
letters[!rep(truthvalues, length = 26)] # extract entries in odd position
letters[rep(truthvalues, times = c(13, 13))] # extract last thirteen entries

letters[letters == "a"] # extract entries equal to "a"
letters[letters != "a"] # extract entries different from "a"
letters[letters < "h"] # extract entries less than "h" (in lexicographic order)
letters[letters <= "h"] # extract entries less than or equal to "h"
letters[letters > "t"] # extract entries greater than "t" (in lexicographic order)
letters[letters >= "t"] # extract entries greater that or or equal to "t"

## Numbers of “great” inventions and scientific discoveries from 1860 to 1959
cat("Yearly Numbers of Important Discoveries:", fill = TRUE)
str(discoveries)

head(discoveries)
tail(discoveries)

sort(discoveries)
table(discoveries)

which(discoveries > 5) + 1859 # years with more than five discoveries
which.max(discoveries) + 1859 # year with the maximum number of discoveries

## loading data from a remote CSV file (American separator and decimal point)
cat("Gender, body temperature and heart rate data:", fill = TRUE)
normtemp <- read.csv("http://stat.slu.edu/~speegle/data/normtemp.csv")
str(normtemp)

## saving data to a local CSV file (Italian separator and decimal point)
write.csv2(normtemp, file = "Rdat02normtemp.csv", row.names = FALSE)

## Car data extracted from the 1974 Motor Trend US magazine
cat("Motor Trend Car Road Tests:", fill = TRUE)
str(mtcars)

head(mtcars)
tail(mtcars)

head(mtcars[, 1:2]) # first two variables
tail(mtcars[, c("mpg", "wt")]) # fuel consumption and weight

mtcars[c(1:2), ] # first two cars
mtcars[mtcars$carb == 2, ] # cars with two carburators...
mtcars[mtcars$carb == 2 & mtcars$gear == 5, ] # ...and five forward gears
mtcars[mtcars$carb == 2 | mtcars$gear == 5, ] # ...or five forward gears

mtcars[1:3, 1:3] # first three variables on first three cars

## Daily air quality measurements in New York (May to September 1973)
cat("New York Air Quality Measurements:", fill = TRUE)
str(airquality)

head(airquality, n = 3)
tail(airquality, n = 9)

mean(airquality$Ozone) # NA
keep <- !is.na(airquality$Ozone)
sum(airquality$Ozone[keep]) / sum(keep)
mean(airquality$Ozone, na.rm = TRUE) # 42.12931 p.p.b.

airquality$Hour # NULL
is.null(airquality$Hour) # TRUE
0 / 0 # Not a Number
is.nan(0 / 0) # TRUE

month.name[1:12 %in% airquality$Month] # months with measurements

## historical dataset in package HistData
cat("Elderton and Pearson's (1910) data on drinking and wages:", fill = TRUE)
str(DrinksWages)

DrinksWages$class
as.numeric(DrinksWages$class) # underlying integer codes

addmargins(xtabs(n ~ class, data = DrinksWages)) # absolute frequencies
addmargins(proportions(xtabs(n ~ class, data = DrinksWages))) # relative frequencies
round(addmargins(proportions(xtabs(n ~ class, data = DrinksWages))), 2)

cat("Occupational categories with more drinkers than non-drinkers:", fill = TRUE)
print(DrinksWages$trade[DrinksWages$drink > DrinksWages$sober])

## vectors can be named
cat("Areas of the World's Major Landmasses:", fill = TRUE)
str(islands)

islands # areas in thousands of square miles
unname(islands)
names(islands)

names(islands)[32:33] <- c("Te Ika-a-Māui", "Te Waipounamu") # Māori language
islands[c("Te Ika-a-Māui", "Te Waipounamu")]
rm(islands)
which(ls("package:datasets") == "islands")
ls("package:datasets")[39:43]

cat("there are", length(islands), "landmasses whose area exceeds 10000 sq mi",
    fill = TRUE
)

## different objects can be bound together in a list
vetCar <- LETTERS[1:3]
vetNum <- 1:5
vetLog <- rep(c(FALSE, TRUE), 2)
listaMista <- list(vetCar, vetNum, vetLog)

cat("A list of three vectors having different lengths and types:", fill = TRUE)
str(listaMista)
is.character(listaMista)
is.numeric(listaMista)
is.logical(listaMista)

length(listaMista) # length of the list
lengths(listaMista) # lengths of the list components

listaMista
listaMista[[1]] # first vector of the list
listaMista[[1]][2] # second entry of the first vector of the list
listaMista[1] # sub-list containing only the first vector of the list
listaMista[2:3] # sub-list containing the second and third vector of the list

## lists can be named
names(listaMista) <- c("lettere", "numeri", "logici")
listaMista
names(listaMista)
names(listaMista[[1]]) # list components are not named in this example

listaMista$numeri
listaMista[["numeri"]]
listaMista["numeri"]
listaMista[c("numeri", "logici")]

## functions can be effectively applied to all elements of a list
OreDiStudio <- list(Qui = c(2, 1, 4, 3), Quo = c(3, 1, 3, 4, 4), Qua = c(2, 2, 3))
OreDiStudio
sum(OreDiStudio$Qui)
lapply(OreDiStudio, sum)
lapply(OreDiStudio, length)
lapply(OreDiStudio, mean)
unlist(lapply(OreDiStudio, mean)) # drop the list structure
as.list(unlist(lapply(OreDiStudio, mean))) # reintroduce the list structure

cat("Total hours of study:", fill = TRUE)
for (duck in names(OreDiStudio)) cat(duck, sum(OreDiStudio[[duck]]), fill = TRUE)
duck # last value taken in the (slower and thus not recommended) "for" cycle

system.time(for (duck in names(OreDiStudio)) sum(OreDiStudio[[duck]]))
system.time(lapply(OreDiStudio, sum))

## a data.frame is a list of vectors all having the same length
is.list(mtcars)
names(mtcars)
length(mtcars)
lengths(mtcars)

nrow(mtcars)
ncol(mtcars)
colnames(mtcars)
rownames(mtcars)

subset(mtcars, cyl == 4, select = -2) # subset observations and select variables

## what is the most common brand in the dataset?
head(strsplit(rownames(mtcars), " "))
mtcars$brand <- unlist(lapply(strsplit(rownames(mtcars), " "), head, n = 1))
mtcars$brand
sort(table(mtcars$brand), decreasing = TRUE)

## a matrix consists of entries all of the same type
is.matrix(mtcars) # a data frame is not a matrix

phoneMatrix <- matrix(1:9, 3, 3, byrow = TRUE)
rownames(phoneMatrix) <- c("A", "B", "C")
colnames(phoneMatrix) <- c("1", "2", "3")
phoneMatrix

cat("Object \"phoneMatrix\" has the following structure:", fill = TRUE)
str(phoneMatrix)

is.numeric(phoneMatrix)
nrow(phoneMatrix)
ncol(phoneMatrix)
dim(phoneMatrix)

phoneMatrix[2, 2] # scalar (length one vector)
phoneMatrix[1:2, 2] # vector (of length two)
phoneMatrix[2, 1:2] # vector (of length two)
phoneMatrix[1:2, 1:2] # submatrix (two by two)

colVector <- as.matrix(1:3)
colVector
rowVector <- t(as.matrix(1:3))
rowVector

rowVector %*% phoneMatrix
phoneMatrix %*% colVector

phoneMatrix %*% phoneMatrix # matrix product
phoneMatrix * phoneMatrix # entry-wise product

det(phoneMatrix) # zero
solve(phoneMatrix + diag(rep(1, 3))) # matrix inversion

## when you feel ready
cat("Play the Proton Game to practice the basics of R!", fill = TRUE)
cat("-------------------------------------------------", fill = TRUE)
library(proton) # load the Proton Game
proton()
