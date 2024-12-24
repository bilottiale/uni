lambda <- 5  # Tasso medio di eventi per unità di tempo
T <- 10      # Tempo totale di osservazione

# Simulazione degli intervalli di tempo esponenziali
set.seed(123)  # Per riproducibilità
inter_arrival_times <- rexp(100, rate = lambda)
event_times <- cumsum(inter_arrival_times)
event_times <- event_times[event_times <= T]  # Considera solo eventi entro il tempo T

# Grafico del processo di Poisson
plot(event_times, 1:length(event_times), type = "s", xlab = "Tempo", ylab = "Numero di eventi",
     main = "Simulazione di un processo di Poisson")
abline(h = 0, col = "gray")

print(event_times)