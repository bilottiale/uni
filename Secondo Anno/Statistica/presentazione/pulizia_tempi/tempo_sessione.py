import fastf1
import pandas as pd

# Enable cache
cache_dir = './fastf1_cache'  # Update with your cache directory
fastf1.Cache.enable_cache(cache_dir)

# Load the session
year = 2024
event_name = "Bahrain Grand Prix"
session_type = "R"  # 'R' for Race

session = fastf1.get_session(year, event_name, session_type)
session.load()  # Load the session data

# Access weather data
weather_data = session.weather_data

# Convert to a DataFrame for easier handling
weather_df = pd.DataFrame({
    'Time': weather_data['Time'],
    'AirTemp': weather_data['AirTemp'],
    'Humidity': weather_data['Humidity'],
    'Pressure': weather_data['Pressure'],
    'Rainfall': weather_data['Rainfall'],
    'TrackTemp': weather_data['TrackTemp'],
    'WindDirection': weather_data['WindDirection'],
    'WindSpeed': weather_data['WindSpeed'],
})

# Save the weather data to a CSV (optional)
weather_df.to_csv('weather_data.csv', index=False)
print("Weather data saved successfully!")

# Example: Merging weather data with lap times
laps = session.laps  # Access lap data
laps['LapTimeSeconds'] = laps['LapTime'].dt.total_seconds()  # Convert LapTime to seconds

# Merge weather data with lap data by matching the closest timestamp
laps_weather = pd.merge_asof(
    laps.sort_values('Time'),
    weather_df.sort_values('Time'),
    on='Time',
    direction='backward'
)

# Save the merged data (optional)
laps_weather.to_csv('laps_with_weather.csv', index=False)
print("Laps with weather data saved successfully!")
