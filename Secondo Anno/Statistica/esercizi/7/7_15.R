# Load necessary libraries
library(fosdata)
library(dplyr)
library(ggplot2)

# Data preparation: Summarize total votes by year and party
election_summary <- pres_election %>%
  group_by(year, party) %>%
  summarize(total_votes = sum(candidatevotes, na.rm = TRUE), .groups = "drop")

# Create the bar chart with facet_wrap
ggplot(election_summary, aes(x = party, y = total_votes, fill = party)) +
  geom_bar(stat = "identity", color = "black") +
  facet_wrap(~ year, ncol = 1) + # One column for better vertical comparison
  labs(
    title = "Totale voti per partito politico (elezioni presidenziali USA 2000-2016)",
    x = "Partito politico",
    y = "Voti totali",
    fill = "Partito politico"
  ) +
  theme_minimal() +
  theme(axis.text.x = element_text(angle = 45, hjust = 1)) # Rotate x-axis labels for readability
