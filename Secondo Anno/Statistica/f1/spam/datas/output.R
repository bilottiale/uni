# Caricamento delle librerie necessarie
library(ggplot2)
library(dplyr)
library(readr) # Per leggere il CSV

# Percorso del dataset
base_path <- "~/Desktop/uni/Secondo Anno/Statistica/presentazione/spam/datas/"
data <- read_csv(file.path(base_path, "final.csv"))

# Funzione per salvare grafici
save_plot <- function(plot, filename) {
  ggsave(file.path(base_path, filename), plot = plot, width = 10, height = 6)
}

# --- Funzione per filtrare e preparare i dati per un evento specifico ---
prepare_data <- function(data, event_name, year, selected_drivers) {
  data %>%
    filter(EventName == event_name & Year == year) %>%
    filter((is.na(Deleted) | Deleted == FALSE) & LapTimeSeconds > 0) %>%
    filter(Driver %in% selected_drivers) %>%
    mutate(Driver = factor(Driver, levels = selected_drivers))
}

# --- Grafico violin plot ---
plot_violin <- function(data, title, filename) {
  p <- ggplot(data, aes(x = Driver, y = LapTimeSeconds, fill = Driver)) +
    geom_violin(trim = FALSE) +
    geom_jitter(aes(color = Compound), size = 1.5, alpha = 0.7, width = 0.2) +
    scale_fill_manual(values = c(
      "VER" = "blue", "HAM" = "cyan", "LEC" = "red", "ALO" = "darkgreen",
      "RUS" = "cyan", "PER" = "blue", "SAI" = "red", "NOR" = "orange",
      "STR" = "darkgreen", "TSU" = "darkblue"
    )) +
    scale_color_manual(values = c("SOFT" = "red", "MEDIUM" = "yellow", "HARD" = "white")) +
    labs(title = title, x = "Pilota", y = "Tempo sul giro (sec)") +
    theme_minimal() +
    theme(legend.position = "bottom") +
    lims(y = c(103, 112)) +
    guides(fill = "none")
  save_plot(p, filename)
}

# --- Grafico strategia gomme ---
plot_strategy <- function(data, title, filename) {
  strategy_data <- data %>%
    group_by(Driver, Compound) %>%
    summarise(LapCount = n()) %>%
    ungroup()
  
  p <- ggplot(strategy_data, aes(x = Driver, y = LapCount, fill = Compound)) +
    geom_bar(stat = "identity", position = "stack", size = 0.2) +
    scale_fill_manual(values = c("SOFT" = "red", "MEDIUM" = "yellow", "HARD" = "azure")) +
    labs(title = title, x = "Pilota", y = "Giri", fill = "Mescola") +
    theme_minimal() +
    theme(legend.position = "bottom") +
    coord_flip()
  save_plot(p, filename)
}

# --- Grafico a linee per giri dei piloti selezionati ---
plot_lap_times <- function(data, title, filename) {
  p <- ggplot(data, aes(x = LapNumber, y = LapTimeSeconds, color = Driver, group = Driver, linetype = Driver)) +
    geom_line() +
    labs(title = title, x = "Numero di Giro", y = "Tempo sul Giro (s)", color = "Pilota", linetype = "Pilota") +
    scale_linetype_manual(values = c("HAM" = "solid", "PER" = "dashed", "VER" = "solid", "RUS" = "dashed")) +
    theme_minimal() +
    theme(legend.position = "bottom")
  save_plot(p, filename)
}

# --- Grafico distribuzione mescole ---
plot_compound_distribution <- function(data, driver, title, filename) {
  p <- ggplot(data, aes(x = Compound, fill = Compound)) +
    geom_bar(color = "black", alpha = 0.7) +
    scale_fill_manual(values = c("SOFT" = "red", "MEDIUM" = "yellow", "HARD" = "azure")) +
    labs(title = title, x = "Mescola", y = "Conteggio") +
    theme_minimal()
  save_plot(p, filename)
}

# --- Esempio di utilizzo delle funzioni ---
selected_drivers <- c("PER", "VER", "LEC", "ALO", "SAI", "HAM", "STR", "RUS", "NOR", "TSU")

# Azerbaijan Grand Prix 2023
data_azerbaijan <- prepare_data(data, "Azerbaijan Grand Prix", 2023, selected_drivers)
plot_violin(data_azerbaijan, "2023 Azerbaijan Grand Prix - Distribuzione Tempi sul Giro", "Azerbaijan_2023_distr_tempo.png")

# Spanish Grand Prix 2023
data_spanish <- prepare_data(data, "Spanish Grand Prix", 2023, selected_drivers)
plot_strategy(data_spanish, "2023 Spanish Grand Prix - Strategia Gomme", "2023_spanish_gomme.png")

# Tempo sul giro di alcuni piloti
data_selected <- data_spanish %>% filter(Driver %in% c("HAM", "PER", "VER", "RUS"))
plot_lap_times(data_selected, "2023 Spanish Grand Prix - Tempo sul Giro di Piloti Selezionati", "2023_spanish_lap_times.png")

# Distribuzione delle mescole per un pilota
plot_compound_distribution(data_azerbaijan %>% filter(Driver == "NOR"), "NOR", "2023 Azerbaijan Grand Prix - Mescole per NOR", "2023_azerbaijan_NOR_compound.png")
