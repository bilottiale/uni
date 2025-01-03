# Caricare i dati
data(mtcars)

# Fitting di un modello di regressione lineare
model <- lm(mpg ~ wt + hp, data = mtcars)

# Predire i valori
mtcars$predicted_mpg <- predict(model, newdata = mtcars)

# Visualizzazione dei risultati con ggplot2
library(ggplot2)

# Grafico scatter con linea di regressione lineare e legenda all'interno del grafico
ggplot(mtcars, aes(x = wt, y = mpg)) +
  geom_point(aes(color = "Dati osservati"), size = 2) + # Punti osservati
  geom_line(aes(y = predicted_mpg, color = "Modello multivariato (predetto)"), size = 1) + # Linea predetta
  geom_smooth(aes(color = "Regressione semplice (lm)"), method = "lm", formula = y ~ x, se = FALSE, linetype = "dashed", size = 1) + # Regressione lineare semplice
  scale_color_manual(values = c("Dati osservati" = "blue", 
                                "Modello multivariato (predetto)" = "red", 
                                "Regressione semplice (lm)" = "green")) + # Personalizza i colori
  labs(title = "Regressione lineare: MPG vs Peso",
       x = "Peso (wt)",
       y = "Consumo di carburante (mpg)",
       color = "Legenda") + # Titolo della legenda
  theme_minimal() +
  theme(legend.position = c(0.85, 0.85), # Posizione in alto a destra
        legend.background = element_rect(fill = "white", color = "black"), # Sfondo e bordo della legenda
        legend.title = element_text(size = 10), # Dimensione del titolo della legenda
        legend.text = element_text(size = 8)) # Dimensione del testo della legendaa

# Analisi dei residui
ggplot(data.frame(residuals = resid(model)), aes(x = residuals)) +
  geom_histogram(binwidth = 1, fill = "lightblue", color = "black") +
  labs(title = "Distribuzione dei residui",
       x = "Residuo",
       y = "Frequenza") +
  theme_minimal()

######################################################

# Modello di regressione lineare
model <- lm(weight ~ height, data = women)

# Visualizzazione del modello
plot(women$height, women$weight, 
     xlab = "Altezza (pollici)", 
     ylab = "Peso (libbre)", 
     main = "Regressione Lineare: Peso vs Altezza")
abline(model, col = "blue", lwd = 2)
legend("topright", legend = "Modello Lineare", col = "blue", lwd = 2)

