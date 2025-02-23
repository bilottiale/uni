# Seed for reproducibility
set.seed(1)

# a. 10.000 simulations of the sum of two dice
# Number of simulations
n_sim <- 10000

# Simulations
dice1 <- sample(1:6, n_sim, replace = TRUE)
dice2 <- sample(1:6, n_sim, replace = TRUE)
dice_sum <- dice1 + dice2

# Barplot
barplot(table(dice_sum), 
        main = "Distribuzione della somma di due dadi",
        xlab = "Somma di due dadi",
        ylab = "Frequenza")

# b. 10.000 simulations of the sum of two modified dice
# trick_dice1 faces: 5,5,5,5,5,5
# trick_dice2 faces: 2,2,2,6,6,6
trick_dice1 <- sample(c(5, 5, 5, 5, 5, 5), n_sim, replace = TRUE)
trick_dice2 <- sample(c(2, 2, 2, 6, 6, 6), n_sim, replace = TRUE)
trick_dice_sum <- trick_dice1 + trick_dice2

# Barplot
barplot(table(trick_dice_sum), 
        main = "Distribuzione della somma di due dadi truccati",
        xlab = "Somma di due dadi",
        ylab = "Frequenza")

# c. 10.000 simulations of the sum of two Sicherman dice
# sicherman_dice1 faces: 1,2,2,3,3,4
# sicherman_dice2 faces: 1,3,4,5,6,8
sicherman_dice1 <- sample(c(1, 2, 2, 3, 3, 4), n_sim, replace = TRUE)
sicherman_dice2 <- sample(c(1, 3, 4, 5, 6, 8), n_sim, replace = TRUE)
sicherman_dice_sum <- sicherman_dice1 + sicherman_dice2

# Barplot
barplot(table(sicherman_dice_sum), 
        main = "Distribuzione della somma di due dadi Sicherman",
        xlab = "Somma di due dadi",
        ylab = "Frequenza")
