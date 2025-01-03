import fastf1

session = fastf1.get_session(2023, 'Italian Grand Prix', 'R')
session.load(laps = True)

th = 1.1

leclerc = session.laps.pick_drivers("LEC").pick_quicklaps(th).reset_index()
print(leclerc[['Driver', 'LapNumber', 'LapTime', 'Compound', 'TyreLife']])
