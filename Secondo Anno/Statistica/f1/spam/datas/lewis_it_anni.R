library(readr)
library(dplyr)
library(ggplot2)
library(caret)
library(randomForest)

set.seed(1)

# Carica i dati
data <- read_csv("~/Desktop/uni/Secondo Anno/Statistica/presentazione/spam/datas/final.csv")

## 2018
# Solo Italian Grand Prix
data <- data %>% filter(EventName == "Italian Grand Prix")

# solo HAM
data_filtered <- data %>%
  filter(Driver == "HAM")

# Filtro i dati per includere solo gli anni <= 2023
data_filtered <- data_filtered %>%
  filter(Year == 2018)

ggplot(data_filtered, aes(x = LapNumber, y = LapTimeSeconds)) +
  geom_point() +
  geom_smooth(method = "lm", se = FALSE) +
  labs(title = "Tempo sul giro di Hamilton all'Italian Grand Prix",
       x = "Numero del Giro",
       y = "Tempo sul Giro (s)") +
  theme_minimal()

# 2019
# Solo Italian Grand Prix
data <- data %>% filter(EventName == "Italian Grand Prix")

# solo HAM
data_filtered <- data %>%
  filter(Driver == "HAM")

# Filtro i dati per includere solo gli anni <= 2023
data_filtered <- data_filtered %>%
  filter(Year == 2019)

ggplot(data_filtered, aes(x = LapNumber, y = LapTimeSeconds)) +
  geom_point() +
  geom_smooth(method = "lm", se = FALSE) +
  labs(title = "Tempo sul giro di Hamilton all'Italian Grand Prix",
       x = "Numero del Giro",
       y = "Tempo sul Giro (s)") +
  theme_minimal()

## 2020
# Solo Italian Grand Prix
data <- data %>% filter(EventName == "Italian Grand Prix")

# solo HAM
data_filtered <- data %>%
  filter(Driver == "HAM")

# Filtro i dati per includere solo gli anni <= 2023
data_filtered <- data_filtered %>%
  filter(Year == 2020)

ggplot(data_filtered, aes(x = LapNumber, y = LapTimeSeconds)) +
  geom_point() +
  geom_smooth(method = "lm", se = FALSE) +
  labs(title = "Tempo sul giro di Hamilton all'Italian Grand Prix",
       x = "Numero del Giro",
       y = "Tempo sul Giro (s)") +
  theme_minimal()

## 2021
# Solo Italian Grand Prix
data <- data %>% filter(EventName == "Italian Grand Prix")

# solo HAM
data_filtered <- data %>%
  filter(Driver == "HAM")

# Filtro i dati per includere solo gli anni <= 2023
data_filtered <- data_filtered %>%
  filter(Year == 2021)

ggplot(data_filtered, aes(x = LapNumber, y = LapTimeSeconds)) +
  geom_point() +
  geom_smooth(method = "lm", se = FALSE) +
  labs(title = "Tempo sul giro di Hamilton all'Italian Grand Prix",
       x = "Numero del Giro",
       y = "Tempo sul Giro (s)") +
  theme_minimal()

## 2022
# Solo Italian Grand Prix
data <- data %>% filter(EventName == "Italian Grand Prix")

# solo HAM
data_filtered <- data %>%
  filter(Driver == "HAM")

# Filtro i dati per includere solo gli anni <= 2023
data_filtered <- data_filtered %>%
  filter(Year == 2022)

ggplot(data_filtered, aes(x = LapNumber, y = LapTimeSeconds)) +
  geom_point() +
  geom_smooth(method = "lm", se = FALSE) +
  labs(title = "Tempo sul giro di Hamilton all'Italian Grand Prix",
       x = "Numero del Giro",
       y = "Tempo sul Giro (s)") +
  theme_minimal()

## 2023
# Solo Italian Grand Prix
data <- data %>% filter(EventName == "Italian Grand Prix")

# solo HAM
data_filtered <- data %>%
  filter(Driver == "HAM")

# Filtro i dati per includere solo gli anni <= 2023
data_filtered <- data_filtered %>%
  filter(Year == 2023)

ggplot(data_filtered, aes(x = LapNumber, y = LapTimeSeconds)) +
  geom_point() +
  geom_smooth(method = "lm", se = FALSE) +
  labs(title = "Tempo sul giro di Hamilton all'Italian Grand Prix",
       x = "Numero del Giro",
       y = "Tempo sul Giro (s)") +
  theme_minimal()
