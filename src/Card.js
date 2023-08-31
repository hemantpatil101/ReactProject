
import starfirst from "./star1.png"
  
export default function Card(props)
{
    let badgetext
    if(props.item.openspots === 0)
    {
        badgetext="SOLD OUT";
    }    
    else if(props.item.location === "Online")
    {
        badgetext="ONLINE";
    }
    return(
        <div className="card">
            
            <img src={props.item.coverimage} className="cardimg"/>    
            {badgetext && <div className="card-badge">{badgetext}</div>}
            <div className="cardstatus">
            
                <img src={starfirst}/>
                <span>{props.item.stats.rating}</span>
                <span> ({props.item.stats.reviewCount}).</span>
                <span>{props.item.country}</span>
            </div>
            <p>{props.item.title}</p>
            <p><span className="bld">From ${props.item.price}</span> / person</p>
        </div>
    )
}