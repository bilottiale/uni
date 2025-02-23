# Load necessary libraries
library(ggplot2)
library(HistData)

# Load the Arbuthnot dataset
data("Arbuthnot", package = "HistData")

# Major plagues
plague_years <- c(1636, 1665, 1681, 1694, 1710)

# Plot
ggplot(Arbuthnot, aes(x = Year, y = Mortality, size = Plague, color = Plague)) +
  geom_point() +
  scale_color_gradient(low = "black", high = "red") + # Gradient black to red
  scale_size_continuous(range = c(1, 5)) +
  labs(x = "Year", y = "Mortality", 
       title = "Mortality in London (1629-1710)", 
       subtitle = "Points colored and sized based on Plague variable") +
  theme_minimal() +
  theme(legend.position = "none") + # Hide legend
  geom_text(data = subset(Arbuthnot, Year %in% plague_years), 
            aes(label = Year), 
            vjust = -1, hjust = 1, size = 3, color = "black") # Labels
