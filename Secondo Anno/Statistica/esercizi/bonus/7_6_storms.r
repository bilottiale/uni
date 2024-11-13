# install.packages("dplyr") # Uncomment to install the dplyr package
# install.packages("ggplot2") # Uncomment to install the ggplot2 package

# Load required libraries
library(dplyr)
library(ggplot2)

str(storms)
unique(storms$category)

# Category colors
category_colors <- c(
  "NA" = "gray",
  "1" = "blue",
  "2" = "green",
  "3" = "yellow",
  "4" = "orange",
  "5" = "red"
)

# Histogram of wind speeds by storm category
ggplot(storms, aes(x = wind, fill = factor(category))) +
  geom_histogram(binwidth = 10, color = "black", alpha = 0.75) +
  labs(title = "Istogramma della pressione per categoria di tempesta",
       x = "Velocità del vento (mph)",
       y = "Frequenza") +
  theme_minimal() +
  scale_fill_manual(values = category_colors)

# Create the histogram of pressure
ggplot(storms, aes(x = pressure, fill = factor(category))) +
  geom_histogram(binwidth = 10, color = "black", alpha = 0.7) +
  labs(title = "Istogramma della pressione per categoria di tempesta",
       x = "Pressione (mb)",
       y = "Conteggio") +
  theme_minimal() +
  scale_fill_manual(values = category_colors)

# Filter data for storms from 2014
storms_2014 <- storms %>%
  filter(year == 2014)

# Plot the position track of each storm
ggplot(storms_2014, aes(x = long, y = lat, color = name)) +
  geom_path() +  # Use geom_path to connect the points and show the track
  geom_point() +  # Plot points for each storm position
  labs(title = "Tempeste nel 2014",
       x = "Longitudine",
       y = "Latitudine") +
  theme_minimal() +
  theme(legend.position = "bottom")

# Identify the storm that made it the furthest North
furthest_north_storm <- storms_2014 %>%
  group_by(name) %>%
  summarize(max_lat = max(lat, na.rm = TRUE)) %>%
  arrange(desc(max_lat)) %>%
  slice(1)

# Print the name of the storm that made it the furthest North
furthest_north_storm