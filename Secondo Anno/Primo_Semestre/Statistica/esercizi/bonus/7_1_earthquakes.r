# install.packages("ggplot2") # Uncomment to install the ggplot2 package

# Load necessary libraries
library(ggplot2)

# Load the "quakes" dataset (built into R)
data(quakes)

# Analyze the structure of the dataset
str(quakes)
head(quakes)

# Magnitude
head(quakes$mag)
min(quakes$mag)
max(quakes$mag)

# Depth
head(quakes$depth)
min(quakes$depth)
max(quakes$depth)

# Latitude
head(quakes$lat)
# Longitude
head(quakes$long)

# Plot
ggplot(quakes, aes(x = long, y = lat, color = depth, size = mag)) +
  geom_point() +  # geom_point() -> Scatter plot
  scale_color_gradient(low = "blue", high = "red") +
  scale_size_continuous(range = c(1, 5)) +
  labs(x = "Longitudine", y = "Latitudine", 
       title = "Posizione terremoti Isole Fiji (anni 60)", 
       color = "Profondità(Km)", 
       size = "Magnitudo") +
  theme_minimal() # Remove bg
