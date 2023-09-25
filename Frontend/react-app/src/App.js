import logo from './logo.svg';
import './App.css';
import Home from './pages/Home';
import { BrowserRouter as Router, Route, Routes } from "react-router-dom";
import Navbar from './component/Navbar';
import Entertainment from './pages/Entertainment/Entertainment';
import Restaurants from './pages/Restaurants/Restaurants';
import Tourist from './pages/TouristPlaces/Tourist';
import Shopping from './pages/Shopping/Shopping';

function App() {
  return (
    <Router>
      <div className="App">
        <Navbar/>
        <Routes>
          <Route path="/" element={<Home />} />
          <Route path="/Entertainment" element={<Entertainment/>} />
          <Route path="/Restaurants" element={<Restaurants/>} />
          <Route path="/TouristPlaces" element={<Tourist/>} />
          <Route path='/Shopping' element={<Shopping/>} />

        </Routes>
      </div>
    </Router>
    
  );
}

export default App;
