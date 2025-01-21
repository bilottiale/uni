library(dplyr)
library(ggplot2)

# Load the storms dataset
data("storms")

# Histogram of wind speeds filled by category
ggplot(storms, aes(x = wind, fill = factor(category))) +
  geom_histogram(binwidth = 10, color = "black") +
  labs(title = "Histogram of Wind Speeds",
       x = "Wind Speed (knots)",
       y = "Count",
       fill = "Category") +
  theme_minimal()

# Histogram of pressure filled by category
ggplot(storms, aes(x = pressure, fill = factor(category))) +
  geom_histogram(binwidth = 5, color = "black") +
  labs(title = "Histogram of Pressure",
       x = "Pressure (mb)",
       y = "Count",
       fill = "Category") +
  theme_minimal()
