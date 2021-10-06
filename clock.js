<script>

    console.log("DATE:");

    let d;
    let time;
    let date;
    const option = { year: 'numeric', month: 'long', day: 'numeric', weekday: 'long' };

    setInterval(() => {

        d = new Date();
        time = d.getHours() + ":" + d.getMinutes() + ":" + d.getSeconds();
        date = d.toLocaleDateString(undefined, option);
        document.getElementById('time').innerHTML = "current time= " + time + "<br>" + "date= " + date;




    }, 1000);


</script>
