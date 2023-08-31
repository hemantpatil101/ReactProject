import firstimg from "./project1.png"
import React from 'react';
import ReactDOM from 'react-dom/client';
import './index.css';
import App from './App';
import reportWebVitals from './reportWebVitals';
import Navbar from './Navbar';
import Hero from './Hero';
import Card from './Card';
import data from "./data";
const root = ReactDOM.createRoot(document.getElementById('root'));

const cards = data.map(item=>{
  return (
    <Card
        item={item}
        key = {item.id}
    />
  )
})

root.render(
  <React.StrictMode>
    <div>
    <Navbar/>
    <Hero/>
    <section className="classlist">
      {cards}
    </section>
    
    </div>
  </React.StrictMode>
);

// If you want to start measuring performance in your app, pass a function
// to log results (for example: reportWebVitals(console.log))
// or send to an analytics endpoint. Learn more: https://bit.ly/CRA-vitals
reportWebVitals();
